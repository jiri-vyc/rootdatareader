#include "OnlyToADataDefinition.h"

OnlyToADataDefinition::OnlyToADataDefinition(std::string fileName, std::string treeName):RootDataDefinition(fileName, treeName){
    this->ToA = new TTreeReaderValue<Double_t>(*this->m_treeReader, "ToA");
}

void * OnlyToADataDefinition::GetPrimarySortedBranch(){
    return (void*)this->ToA;
}

SingleDataEntry * OnlyToADataDefinition::GetEntry(){
    this->m_dataEntry->SetToA(**this->ToA);
    return this->m_dataEntry;
}