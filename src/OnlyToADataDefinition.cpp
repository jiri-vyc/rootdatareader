#include "OnlyToADataDefinition.h"
#include <typeinfo>

OnlyToADataDefinition::~OnlyToADataDefinition(){
    delete this->m_dataEntry;
    if (this->ToA) delete this->ToA;
}

OnlyToADataDefinition::OnlyToADataDefinition(std::string fileName, std::string treeName):RootDataDefinition(fileName, treeName){
    this->ToA = new TTreeReaderValue<Double_t>(*this->m_treeReader, "ToA");
}

void * OnlyToADataDefinition::GetPrimarySortedBranch(){
    std::cout << std::setprecision(15) << **this->ToA << std::endl;
    return (void*)this->ToA;
}

SingleDataEntry * OnlyToADataDefinition::GetEntry(){
    this->m_dataEntry->SetToA(**this->ToA);
    return new SinglePixelToA(this->m_dataEntry);
}
