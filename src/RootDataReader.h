#pragma once
#include "RootDataDefinition.h"
#include "DataEntryInterval.h"

/** 
@brief Class responsible for reading data of various structure in the ROOT format (TTree within TFile). 

RootDataReader provides a facade for accessing arbitrary data from ROOT files, providing them in C++ custom interval class, standard C++ vector or a JSON format.

After setting the proper RootDataDefinition, RootDataReader will know the structure of the data it will be working with. 
Then it can read data of such structure and retrieve them as a whole, as a std::vector, as a interval, print them to stdout etc.
*/
class RootDataReader {
    private:
        /// Last created and returned interval. Keep reference to it for cleanup purposes
        DataEntryInterval * m_interval = nullptr;
        /// Specifies the definition of the structure of the data in the root file
        RootDataDefinition * m_definition;
        /// ROOT TTreeReader for accessing the values in ROOT TTree TBranches
        TTreeReader * m_treeReader;
        /// Check if all necessary requirements are set up for this reader to begin reading
        bool AllReadyToRead();
        /// Get current value of primary sorted branch of currently attached DataDefinition

        /// Perform the binary search for provided value on the current tree and find the starting index
        template <typename T>
        Long64_t BinarySearchForValue(T searchValue, Long64_t currIndex, Long64_t minIndex, Long64_t maxIndex){
            // If the indexes meet, the value was found. Return.
            if (currIndex == minIndex || currIndex == maxIndex){
                return currIndex;
            }
            this->m_treeReader->SetEntry(currIndex + 1);
            T nextValue = this->GetCurrentValue<T>();
            this->m_treeReader->SetEntry(currIndex);

            // If the current value meets the search condition, return. (current value is < than the searched one, the immediate next is already >=)
            if (this->GetCurrentValue<T>() < searchValue && nextValue >= searchValue){
                // std::cout << std::setprecision(13) << "next value: " << nextValue << std::endl;
                // std::cout << std::setprecision(13)  << "searchValue: " << searchValue << std::endl;
                // std::cout << std::setprecision(13)  << "current value: " << this->GetCurrentValue<T>() << std::endl;
                return currIndex;
            }

            // Search in lower/higher halves of the tree recursively, depending on the value
            if (this->GetCurrentValue<T>() < searchValue){
                return this->BinarySearchForValue(searchValue, (currIndex + maxIndex) / 2, currIndex, maxIndex);
            } else {
                return this->BinarySearchForValue(searchValue, (currIndex + minIndex) / 2, minIndex, currIndex);
            }
        }
        /// Returns a current value of the primary sorted branch of the type specified
        template <typename T>
        T GetCurrentValue(){
            return **((TTreeReaderValue<T>*)this->m_definition->GetPrimarySortedBranch());
        }
    public:
        RootDataReader();
        ~RootDataReader();
        /// Returns a reference to a native ROOT's TTreeReader object
        TTreeReader * GetTreeReader();
        /// Assigns given data definition to this reader - data read will be in format specified by the definition
        void SetDataDefinition(RootDataDefinition * definition);
        /// Assigns given data interval to this reader - resulting data will be in form of this interval
        void SetDataInterval(DataEntryInterval * interval);
        /// Invokes default functionality of TTree::Print() of the loaded ROOT TTree - prints contents of the tree
        void Print();
        /// Invokes default functionality of TTree::Scan() of the loaded ROOT TTree - prints contents of the tree
        void Scan();
        /// Prints a list of all branches within the loaded ROOT TTree, uses TTree::GetListOfBranches() - doesn't have to correspond with used data definition!
        void GetListOfBranches();
        /// Prints the first entry in the specified TTree within specified TFile, according to specified RootDataDefinition
        /// @return true if success
        /// @return false if there was an error and printing couldn't happen
        bool PrintFirst();
        /// Returns a single data entry at given index. Entry returned is of type specified in selected RootDataDefinition
        SingleDataEntry * GetEntryAt(unsigned int index);
        /// Returns an interval of data entries, starting from index in first parameter, ending at index in the second parameter (not inclusive): <indexFrom, indexTo)
        DataEntryInterval * GetInterval(unsigned int indexFrom, unsigned int indexTo);
        /**
        @brief Returns an index of entry with its value closest to given searchValue

        Searches the primary sorted branch (specified by data definition) of the tree for value given by searchValue and returns its index. Determines where the values in the tree start to be greated than the parameter.

        @return The last index on which the value is lower than searched value. Returns 0 if the searchValue is lower than 0th entry.        */
        template <typename T>
        unsigned int GetStartingIndex(T searchValue){
            Long64_t entriesCnt = this->m_treeReader->GetEntries(false);
            Long64_t currIndex = entriesCnt/2;
            return this->BinarySearchForValue<T>(searchValue, currIndex, 0, entriesCnt);
        }
        /// Searches for interval, where the values are in between supplied parameters. Uses PrimarySortedBranch of the data definition
        template <typename T>
        DataEntryInterval * GetIntervalBySearch(T valueFrom, T valueTo){

            std::cout << this->GetStartingIndex<T>(valueTo) << std::endl;

            return this->GetInterval(this->GetStartingIndex<T>(valueFrom), this->GetStartingIndex<T>(valueTo) + 1);
        }
};