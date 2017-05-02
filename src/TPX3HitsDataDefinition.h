#pragma once
#include "RootDataDefinition.h"
#include "SingleTPX3Hit.h"
/**
@brief Class defining the structure of data within root file containing only one value (of type double) - ToA
*/
class TPX3HitsDataDefinition: public RootDataDefinition {
    private:
        TTreeReaderValue<Double_t> * ToA;
        TTreeReaderValue<Int_t> * ToT;
        TTreeReaderValue<Short_t> * PixX;
        TTreeReaderValue<Short_t> * PixY;
        TTreeReaderValue<ULong64_t> * sToA;
        TTreeReaderValue<UInt_t> * fToA;
        TTreeReaderValue<ULong64_t> * triggerNo;
    protected:
        SingleTPX3Hit * m_dataEntry = new SingleTPX3Hit();
    public:
        ~TPX3HitsDataDefinition();
        TPX3HitsDataDefinition(std::string fileName, std::string treeName);
        void * GetPrimarySortedBranch();
        SingleDataEntry * GetEntry();
};