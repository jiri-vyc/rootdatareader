#pragma once
#include "RootDataDefinition.h"
#include "SinglePixelToA.h"

class OnlyToADataDefinition: public RootDataDefinition {
    private:
        TTreeReaderValue<Double_t> * ToA;
    protected:
        SinglePixelToA * m_dataEntry = new SinglePixelToA();
    public:
        OnlyToADataDefinition(std::string fileName, std::string treeName);
        void * GetPrimarySortedBranch();
        SingleDataEntry * GetEntry();
};