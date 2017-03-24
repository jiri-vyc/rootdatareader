#pragma once
#include "RootDataDefinition.h"
#include <exception>

/** 
Class responsible for reading data of various structure in the ROOT format (TTree within TFile). 

RootDataReader provides a facade for accessing arbitrary data from ROOT files, providing them in C++ custom interval class, standard C++ vector or a JSON format.

After setting the proper RootDataDefinition, RootDataReader will know the structure of the data it will be working with. 
Then it can read data of such structure and retrieve them as a whole, as a std::vector, as a interval, print them to stdout etc.
*/
class RootDataReader {
    private:
        /// Specifies the definition of the structure of the data in the root file
        RootDataDefinition * m_definition;
        /// Specifies the root TFile with the data
        TFile * m_rootFile;
        /// Specifies the name of the TTree within the TFile containing the data
        std::string m_treeName;
        /// ROOT TTreeReader for accessing the values in ROOT TTree TBranches
        TTreeReader * m_reader;
        /// Check if all necessary requirements are set up for this reader to begin reading
        bool AllReadyToRead();
    public:
        RootDataReader();
        ~RootDataReader();
        TTreeReader * GetTreeReader();
        void SetDataDefinition(RootDataDefinition * definition);
        void Scan();
        /// Prints the first entry in the specified TTree within specified TFile, according to specified RootDataDefinition
        /// @return true if success
        /// @return false if there was an error and printing couldn't happen
        bool PrintFirst();
        SingleDataEntry * GetEntryAt(unsigned int index);
};