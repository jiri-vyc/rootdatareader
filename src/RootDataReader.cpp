#include "RootDataReader.h"

RootDataReader::RootDataReader(){
    this->m_definition = nullptr;
    this->m_treeReader = nullptr;
}

RootDataReader::~RootDataReader(){
    if (this->m_interval){
        delete this->m_interval;
    }
}

void RootDataReader::SetDataDefinition(RootDataDefinition * definition){
    this->m_definition = definition;
    this->m_treeReader = definition->GetReader();
}

void RootDataReader::SetDataInterval(DataEntryInterval * interval){
    this->m_interval = interval;
}


void RootDataReader::Scan(){
    this->m_definition->GetTree()->Scan();
}

void RootDataReader::Print(){
    this->m_definition->GetTree()->Print();
}

void RootDataReader::GetListOfBranches(){
    this->m_definition->GetTree()->GetListOfBranches()->Print();
}

bool RootDataReader::PrintFirst(){
    if (!this->AllReadyToRead()){
        return false;
    }
    this->m_treeReader->SetEntry(0);
    std::cout << this->m_definition->GetEntry() << std::endl;
    return true;
}

SingleDataEntry * RootDataReader::GetEntryAt(unsigned int index){
    if (!this->AllReadyToRead()){
        std::cout << "Error: data definition or data reader has not been set." << std::endl;
        return nullptr;
    }
    // SetEntry returns EEntryStatus, where kEntryValid = 0. All other are error codes.
    if (!this->m_treeReader->SetEntry(index)){
        return this->m_definition->GetEntry();
    }
    std::cout << "Error getting an entry from the tree. You can use RootDataReader::Print() to check available branches." << std::endl;
    return nullptr;
}

DataEntryInterval * RootDataReader::GetInterval(unsigned int indexFrom, unsigned int indexTo){
    SingleDataEntry * currEntry;
    if (!this->m_interval) {
        this->m_interval = new DataEntryInterval();
    }
    this->m_interval->Clear();
    for (unsigned int i = indexFrom; i < indexTo; i++){
        currEntry = this->GetEntryAt(i);
        if (currEntry){
            this->m_interval->PushBack(currEntry);
        } else {
            break;
        }
    }
    return this->m_interval;
}

bool RootDataReader::AllReadyToRead(){
    return (this->m_definition && this->m_treeReader);
}

TTreeReader * RootDataReader::GetTreeReader(){
    return this->m_treeReader;
}