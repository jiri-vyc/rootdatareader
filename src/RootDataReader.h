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
    public:
        RootDataReader();
        ~RootDataReader();
        /// Returns a reference to a native ROOT's TTreeReader object
        TTreeReader * GetTreeReader();
        /// Assigns given data definition to this reader - data read will be in format specified by the definition
        void SetDataDefinition(RootDataDefinition * definition);
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
        DataEntryInterval * GetInterval(unsigned int indexFrom, unsigned int indexTo);
};