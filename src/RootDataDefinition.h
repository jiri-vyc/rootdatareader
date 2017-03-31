#pragma once
#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "SingleDataEntry.h"
#include <string>

/** 
@brief Abstract interface for defining a structure of the data in the ROOT files, process how to read these data and save them to desired data objects.

All data structure definitions have to derive from this interface and have to contain methods described by it.

Defines:
- which ROOT file, tree and branches are used.
- which data to read from the ROOT tree
- which data object (derived from SingleDataEntry) will be used to represent and store these data
- how to get values of the data object (SingleDataEntry) from the values in the ROOT tree and its branches
*/
class RootDataDefinition{
    protected:
        TTree * m_tree;
        SingleDataEntry * m_dataEntry;
        std::string m_treeName;
        TFile * m_rootFile;
        std::string m_fileName;
        TTreeReader * m_treeReader;
    public:
        RootDataDefinition(std::string fileName, std::string treeName);
        virtual ~RootDataDefinition(){};
        TTreeReader * GetReader();
        TTree * GetTree();
        TFile * GetFile();
        std::string GetTreeName();
        std::string GetFileName();

        // Methods that HAVE TO be overriden in child classes
        virtual void* GetPrimarySortedBranch() = 0;
        virtual SingleDataEntry * GetEntry() = 0;
};