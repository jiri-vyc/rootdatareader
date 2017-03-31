#include "RootDataReader.h"
#include <iostream>

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

void RootDataReader::Scan(){
    this->m_definition->GetTree()->Scan();
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
        return nullptr;
    }
    this->m_treeReader->SetEntry(index);
    return this->m_definition->GetEntry();
}

DataEntryInterval * RootDataReader::GetInterval(unsigned int indexFrom, unsigned int indexTo){
    if (this->m_interval) {
        delete this->m_interval;
    }
    this->m_interval = new DataEntryInterval();
    for (unsigned int i = indexFrom; i < indexTo; i++){
        this->m_interval->PushBack(this->GetEntryAt(i));
    }
    return this->m_interval;
}

bool RootDataReader::AllReadyToRead(){
    return (this->m_definition && this->m_treeReader);
}

TTreeReader * RootDataReader::GetTreeReader(){
    return this->m_treeReader;
}