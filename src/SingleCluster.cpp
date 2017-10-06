#include "SingleCluster.h"

using namespace rapidjson;

SingleCluster::SingleCluster(){
	this->ToA = nullptr;
	this->ToT = nullptr;
	this->PixX = nullptr;
	this->PixY = nullptr;
}

SingleCluster::SingleCluster(SingleCluster * otherEntry){
	this->ToA = nullptr;
	this->ToT = nullptr;
	this->PixX = nullptr;
	this->PixY = nullptr;
    this->SetClstrSize(otherEntry->GetClstrSize());
    this->SetToA(otherEntry->GetToA());
    this->SetToT(otherEntry->GetToT());
    this->SetPixX(otherEntry->GetPixX());
    this->SetPixY(otherEntry->GetPixY());
    this->SetTriggerNo(otherEntry->GetTriggerNo());
}

SingleCluster::~SingleCluster(){
    if(this->ToA != nullptr) delete [] this->ToA;
	if(this->ToT != nullptr) delete [] this->ToT;
	if(this->PixX != nullptr) delete [] this->PixX;
	if(this->PixY != nullptr) delete [] this->PixY;
}

void SingleCluster::Print(std::ostream& os) const{
    os << this->GetClstrSize() << " ";
    // os << this->GetToA() << " ";
    // os << this->GetToT() << " ";
    // os << this->GetPixX() << " ";
    // os << this->GetPixY() << " ";
    os << this->GetTriggerNo() << " ";
}

void SingleCluster::JSONify(Writer<StringBuffer> & writer){
    writer.StartObject();
    writer.Key("clstrSize");
	writer.Int(this->GetClstrSize());
	writer.Key("PixX");
    writer.StartArray();
    for (Int_t i = 0; i < this->GetClstrSize(); i++)
    {
	    writer.Int(this->GetPixX()[i]);
    }
    writer.EndArray();
	writer.Key("PixY");
    writer.StartArray();
    for (Int_t i = 0; i < this->GetClstrSize(); i++)
    {
	    writer.Int(this->GetPixY()[i]);
    }
    writer.EndArray();
	writer.Key("ToA");
    writer.StartArray();
    for (Int_t i = 0; i < this->GetClstrSize(); i++)
    {
	    writer.Double(this->GetToA()[i]);
    }
    writer.EndArray();
	writer.Key("ToT");
    writer.StartArray();
    for (Int_t i = 0; i < this->GetClstrSize(); i++)
    {
	    writer.Int(this->GetToT()[i]);
    }
    writer.EndArray();
	writer.Key("TriggerNo");
	writer.Int(this->GetTriggerNo());
    writer.EndObject();
}

Int_t SingleCluster::GetClstrSize() const{
    return this->clstrSize;
}

void SingleCluster::SetClstrSize(Int_t clstrSize){
    this->clstrSize = clstrSize;
}

Double_t * SingleCluster::GetToA() const{
    return this->ToA;
}

void SingleCluster::SetToA(Double_t * ToA){
    if(this->ToA != nullptr) delete [] this->ToA;
    this->ToA = new Double_t[this->GetClstrSize()];
    for (Int_t i = 0; i < this->GetClstrSize(); i++){
        this->ToA[i] = ToA[i];
    }
}

void SingleCluster::SetToA(TTreeReaderArray<Double_t> * ToA){
    if(this->ToA != nullptr) delete [] this->ToA;
    this->ToA = new Double_t[ToA->GetSize()];
    for (unsigned int i = 0; i < ToA->GetSize(); i++){
        this->ToA[i] = (*ToA)[i];
    }
}

Int_t * SingleCluster::GetToT() const{
    return this->ToT;
}

void SingleCluster::SetToT(Int_t * ToT){
	if(this->ToT != nullptr) delete [] this->ToT;
    this->ToT = new Int_t[this->GetClstrSize()];
    for (Int_t i = 0; i < this->GetClstrSize(); i++){
        this->ToT[i] = ToT[i];
    }
}
void SingleCluster::SetToT(TTreeReaderArray<Int_t> * ToT){
	if(this->ToT != nullptr) delete [] this->ToT;
    this->ToT = new Int_t[ToT->GetSize()];
    for (unsigned int i = 0; i < ToT->GetSize(); i++){
        this->ToT[i] = (*ToT)[i];
    }
}

Short_t * SingleCluster::GetPixX() const{
    return this->PixX;
}

void SingleCluster::SetPixX(Short_t * PixX){
	if(this->PixX != nullptr) delete [] this->PixX;
    this->PixX = new Short_t[this->GetClstrSize()];
    for (Int_t i = 0; i < this->GetClstrSize(); i++){
        this->PixX[i] = PixX[i];
    }
}
void SingleCluster::SetPixX(TTreeReaderArray<Short_t> * PixX){
	if(this->PixX != nullptr) delete [] this->PixX;
    this->PixX = new Short_t[PixX->GetSize()];
    for (unsigned int i = 0; i < PixX->GetSize(); i++){
        this->PixX[i] = (*PixX)[i];
    }
}


Short_t * SingleCluster::GetPixY() const{
    return this->PixY;
}

void SingleCluster::SetPixY(Short_t * PixY){
	if(this->PixY != nullptr) delete [] this->PixY;
    this->PixY = new Short_t[this->GetClstrSize()];
    for (Int_t i = 0; i < this->GetClstrSize(); i++){
        this->PixY[i] = PixY[i];
    }
}
void SingleCluster::SetPixY(TTreeReaderArray<Short_t> * PixY){
	if(this->PixY != nullptr) delete [] this->PixY;
    this->PixY = new Short_t[PixY->GetSize()];
    for (unsigned int i = 0; i < PixY->GetSize(); i++){
        this->PixY[i] = (*PixY)[i];
    }
}

Int_t SingleCluster::GetTriggerNo() const{
    return this->triggerNo;
}

void SingleCluster::SetTriggerNo(Int_t triggerNo){
    this->triggerNo = triggerNo;
}