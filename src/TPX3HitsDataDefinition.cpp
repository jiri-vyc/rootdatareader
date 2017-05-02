#include "TPX3HitsDataDefinition.h"

TPX3HitsDataDefinition::~TPX3HitsDataDefinition(){
    delete this->m_dataEntry;
    if (this->ToA) delete this->ToA;
    if (this->ToT) delete this->ToT;
    if (this->PixX) delete this->PixX;
    if (this->PixY) delete this->PixY;
    if (this->sToA) delete this->sToA;
    if (this->fToA) delete this->fToA;
    if (this->triggerNo) delete this->triggerNo;
}

TPX3HitsDataDefinition::TPX3HitsDataDefinition(std::string fileName, std::string treeName):RootDataDefinition(fileName, treeName){
    this->ToA = new TTreeReaderValue<Double_t>(*this->m_treeReader, "ToA");
    this->ToT = new TTreeReaderValue<Int_t>(*this->m_treeReader, "ToT");
    this->PixX = new TTreeReaderValue<Short_t>(*this->m_treeReader, "PixX");
    this->PixY = new TTreeReaderValue<Short_t>(*this->m_treeReader, "PixY");
    this->sToA = new TTreeReaderValue<ULong64_t>(*this->m_treeReader, "sToA");
    this->fToA = new TTreeReaderValue<UInt_t>(*this->m_treeReader, "fToA");
    this->triggerNo = new TTreeReaderValue<ULong64_t>(*this->m_treeReader, "triggerNo");
}

void * TPX3HitsDataDefinition::GetPrimarySortedBranch(){
    return (void*)this->ToA;
}

SingleDataEntry * TPX3HitsDataDefinition::GetEntry(){
    this->m_dataEntry->SetToA(**this->ToA);
    this->m_dataEntry->SetToT(**this->ToT);
    this->m_dataEntry->SetPixX(**this->PixX);
    this->m_dataEntry->SetPixY(**this->PixY);
    this->m_dataEntry->SetSToA(**this->sToA);
    this->m_dataEntry->SetFToA(**this->fToA);
    this->m_dataEntry->SetTriggerNo(**this->triggerNo);
    return new SingleTPX3Hit(this->m_dataEntry);
}