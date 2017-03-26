#include "RootDataDefinition.h"

TTreeReader * RootDataDefinition::GetReader(){
    return this->m_treeReader;
}

TTree * RootDataDefinition::GetTree(){
    if (!this->m_tree){
        this->m_tree = (TTree*)(this->GetFile()->Get(this->GetTreeName().c_str()));
    }
    return this->m_tree;
}

TFile * RootDataDefinition::GetFile(){
    return this->m_rootFile;
}

std::string RootDataDefinition::GetTreeName(){
    return this->m_treeName;
}

std::string RootDataDefinition::GetFileName(){
    return this->m_fileName;
}

RootDataDefinition::RootDataDefinition(std::string fileName, std::string treeName){
    this->m_tree = nullptr;
    this->m_treeName = treeName;
    this->m_fileName = fileName;
    this->m_rootFile = new TFile(fileName.c_str());
    this->m_treeReader = new TTreeReader(treeName.c_str(), this->m_rootFile);
}