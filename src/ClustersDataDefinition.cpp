#include "ClustersDataDefinition.h"

ClustersDataDefinition::~ClustersDataDefinition(){
    delete this->m_dataEntry;
    if (this->clstrSize) delete this->clstrSize;
    if (this->ToA) delete this->ToA;
    if (this->ToT) delete this->ToT;
    if (this->PixX) delete this->PixX;
    if (this->PixY) delete this->PixY;
    if (this->triggerNo) delete this->triggerNo;
    if (this->min_ToA) delete this->min_ToA;
    if (this->coincidence_group) delete this->coincidence_group;
    if (this->coincidence_group_size) delete this->coincidence_group_size;
}

ClustersDataDefinition::ClustersDataDefinition(std::string fileName, std::string treeName):RootDataDefinition(fileName, treeName){
    this->clstrSize = new TTreeReaderValue<Int_t>(*this->m_treeReader, "clstrSize");
    this->ToA = new TTreeReaderArray<Double_t>(*this->m_treeReader, "ToA");
    this->ToT = new TTreeReaderArray<Int_t>(*this->m_treeReader, "ToT");
    this->PixX = new TTreeReaderArray<Short_t>(*this->m_treeReader, "PixX");
    this->PixY = new TTreeReaderArray<Short_t>(*this->m_treeReader, "PixY");
    this->triggerNo = new TTreeReaderValue<Int_t>(*this->m_treeReader, "triggerNo");
    this->min_ToA = new TTreeReaderValue<Double_t>(*this->m_treeReader, "min_ToA");
}

void * ClustersDataDefinition::GetPrimarySortedBranch(){
    return (void*)this->min_ToA;
}

SingleDataEntry * ClustersDataDefinition::GetEntry(){
    this->m_dataEntry->SetClstrSize(**this->clstrSize);
    this->m_dataEntry->SetToA(this->ToA);
    this->m_dataEntry->SetToT(this->ToT);
    this->m_dataEntry->SetPixX(this->PixX);
    this->m_dataEntry->SetPixY(this->PixY);
    this->m_dataEntry->SetTriggerNo(**this->triggerNo);
    this->m_dataEntry->SetMinToA(**this->min_ToA);
    return new SingleCluster(this->m_dataEntry);
}