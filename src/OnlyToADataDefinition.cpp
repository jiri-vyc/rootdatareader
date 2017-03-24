#include "OnlyToADataDefinition.h"

OnlyToADataDefinition::OnlyToADataDefinition(std::string fileName, std::string treeName):RootDataDefinition(fileName, treeName){
    this->ToA = new TTreeReaderValue<Double_t>(*this->m_treeReader, "ToA");
}

std::string OnlyToADataDefinition::GetPrimarySortedBranch(){
    return "ToA";
}

SingleDataEntry * OnlyToADataDefinition::GetEntry(){
    this->m_dataEntry->SetToA(**this->ToA);
    return this->m_dataEntry;
}