#include "SinglePixelToA.h"

using namespace rapidjson;

SinglePixelToA::SinglePixelToA(){

}

SinglePixelToA::~SinglePixelToA(){

}

void SinglePixelToA::print(std::ostream& os) const{
    os << this->GetToA();
}

void SinglePixelToA::JSONify(Writer<StringBuffer> & writer){
    writer.StartObject();
	writer.Key("ToA");
	writer.Double(this->GetToA());
    writer.EndObject();
}

Double_t SinglePixelToA::GetToA() const{
    return this->ToA;
}

void SinglePixelToA::SetToA(Double_t ToA){
    this->ToA = ToA;
}