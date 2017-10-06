#pragma once
#include "RootDataDefinition.h"
#include "SingleCluster.h"

/**
@brief Class defining the structure of data within root file containing clustered data
*/
class ClustersDataDefinition: public RootDataDefinition {
    private:
        TTreeReaderValue<Int_t> * clstrSize;
        TTreeReaderArray<Double_t> * ToA;
        TTreeReaderArray<Int_t> * ToT;
        TTreeReaderArray<Short_t> * PixX;
        TTreeReaderArray<Short_t> * PixY;
        TTreeReaderValue<Int_t> * triggerNo;
        TTreeReaderValue<ULong64_t> * coincidence_group;
        TTreeReaderValue<Short_t> * coincidence_group_size;
    protected:
        SingleCluster * m_dataEntry = new SingleCluster();
    public:
        ~ClustersDataDefinition();
        ClustersDataDefinition(std::string fileName, std::string treeName);
        void * GetPrimarySortedBranch();
        SingleDataEntry * GetEntry();
};