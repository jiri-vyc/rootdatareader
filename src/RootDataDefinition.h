#pragma once
#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
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

Types for TTreeReaderValues based on branch types of the TTree:

C : a character string terminated by the 0 character

B : an 8 bit signed integer (Char_t)

b : an 8 bit unsigned integer (UChar_t)

S : a 16 bit signed integer (Short_t)

s : a 16 bit unsigned integer (UShort_t)

I : a 32 bit signed integer (Int_t)

i : a 32 bit unsigned integer (UInt_t)

F : a 32 bit floating point (Float_t)

D : a 64 bit floating point (Double_t)

L : a 64 bit signed integer (Long64_t)

l : a 64 bit unsigned integer (ULong64_t)

O : [the letter o, not a zero] a boolean (Bool_t)
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
        template <typename T>
        unsigned int GetStartingIndex(T startValue){
            T primaryBranch;
            
            this->m_treeReader->SetEntry(0);

            primaryBranch = **((TTreeReaderValue<T>*)(this->GetPrimarySortedBranch()));

            std::cout << std::setprecision(15) << primaryBranch << std::endl;
            std::cout << std::setprecision(15) << startValue << std::endl;

            return 42;
        }

        // Methods that HAVE TO be overriden in child classes
        virtual void * GetPrimarySortedBranch() = 0;
        virtual SingleDataEntry * GetEntry() = 0;
};