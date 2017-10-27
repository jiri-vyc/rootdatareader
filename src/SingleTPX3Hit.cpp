#include "SingleTPX3Hit.h"

using namespace rapidjson;

SingleTPX3Hit::SingleTPX3Hit(){

}

SingleTPX3Hit::SingleTPX3Hit(SingleTPX3Hit * otherEntry){
    this->SetToA(otherEntry->GetToA());
    this->SetToT(otherEntry->GetToT());
    this->SetPixX(otherEntry->GetPixX());
    this->SetPixY(otherEntry->GetPixY());
    this->SetSToA(otherEntry->GetSToA());
    this->SetFToA(otherEntry->GetFToA());
    this->SetTriggerNo(otherEntry->GetTriggerNo());
}

SingleTPX3Hit::~SingleTPX3Hit(){

}

void SingleTPX3Hit::Print(std::ostream& os) const{
    os << this->GetToA() << " ";
    os << this->GetToT() << " ";
    os << this->GetPixX() << " ";
    os << this->GetPixY() << " ";
    os << this->GetSToA() << " ";
    os << this->GetFToA() << " ";
    os << this->GetTriggerNo() << " ";
}

void SingleTPX3Hit::JSONify(Writer<StringBuffer> & writer){
    writer.StartObject();
	writer.Key("pixX");
	writer.Int(this->GetPixX());
	writer.Key("pixY");
	writer.Int(this->GetPixY());
	writer.Key("ToA");
	writer.Double(this->GetToA());
	writer.Key("ToT");
	writer.Int(this->GetToT());
	writer.Key("sToA");
	writer.Uint64(this->GetSToA());
	writer.Key("fToA");
	writer.Uint(this->GetFToA());
	writer.Key("TriggerNo");
	writer.Uint64(this->GetTriggerNo());
    writer.EndObject();
}

Double_t SingleTPX3Hit::GetToA() const{
    return this->ToA;
}

void SingleTPX3Hit::SetToA(Double_t ToA){
    this->ToA = ToA;
}

Int_t SingleTPX3Hit::GetToT() const{
    return this->ToT;
}

void SingleTPX3Hit::SetToT(Int_t ToT){
    this->ToT = ToT;
}

Short_t SingleTPX3Hit::GetPixX() const{
    return this->PixX;
}

void SingleTPX3Hit::SetPixX(Short_t PixX){
    this->PixX = PixX;
}

Short_t SingleTPX3Hit::GetPixY() const{
    return this->PixY;
}

void SingleTPX3Hit::SetPixY(Short_t PixY){
    this->PixY = PixY;
}

ULong64_t SingleTPX3Hit::GetSToA() const{
    return this->sToA;
}

void SingleTPX3Hit::SetSToA(ULong64_t sToA){
    this->sToA = sToA;
}

UInt_t SingleTPX3Hit::GetFToA() const{
    return this->fToA;
}

void SingleTPX3Hit::SetFToA(UInt_t fToA){
    this->fToA = fToA;
}

ULong64_t SingleTPX3Hit::GetTriggerNo() const{
    return this->triggerNo;
}

void SingleTPX3Hit::SetTriggerNo(ULong64_t triggerNo){
    this->triggerNo = triggerNo;
}