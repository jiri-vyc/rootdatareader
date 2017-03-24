#include "RootDataReader.h"
#include <iostream>

RootDataReader::RootDataReader(){
    this->m_definition = nullptr;
    this->m_reader = nullptr;
}

RootDataReader::~RootDataReader(){

}

void RootDataReader::SetDataDefinition(RootDataDefinition * definition){
    this->m_definition = definition;
    this->m_reader = definition->GetReader();
}

void RootDataReader::Scan(){
    ((TTree*)this->m_rootFile->Get(this->m_treeName.c_str()))->Scan();
}

bool RootDataReader::PrintFirst(){
    if (!this->AllReadyToRead()){
        return false;
    }
    this->m_reader->SetEntry(0);
    std::cout << this->m_definition->GetEntry() << std::endl;
    return true;
}

SingleDataEntry * RootDataReader::GetEntryAt(unsigned int index){
    if (!this->AllReadyToRead()){
        return nullptr;
    }
    this->m_reader->SetEntry(index);
    return this->m_definition->GetEntry();
}

bool RootDataReader::AllReadyToRead(){
    return (this->m_definition && this->m_reader);
}

TTreeReader * RootDataReader::GetTreeReader(){
    return this->m_reader;
}