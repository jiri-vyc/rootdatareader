#pragma once
#include "RootDataDefinition.h"
#include "SinglePixelToA.h"
/**
@brief Class defining the structure of data within root file containing only one value (of type double) - ToA
*/
class OnlyToADataDefinition: public RootDataDefinition {
    private:
        TTreeReaderValue<Double_t> * ToA;
    protected:
        SinglePixelToA * m_dataEntry = new SinglePixelToA();
    public:
        ~OnlyToADataDefinition();
        OnlyToADataDefinition(std::string fileName, std::string treeName);
        void * GetPrimarySortedBranch();
        SingleDataEntry * GetEntry();
};