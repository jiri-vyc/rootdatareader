#pragma once
#include "TTreeReaderValue.h"
#include "SingleDataEntry.h"

/**
@brief Class defining the data object containing values about single hit on the TPX3 detector -ToA, ToT, coordinates, sToA, fToA
*/
class SingleTPX3Hit: public SingleDataEntry {
private:
	Double_t ToA;
	Int_t ToT;
	Short_t PixX;
	Short_t PixY;
    ULong64_t sToA;
    UInt_t fToA;
    ULong64_t triggerNo;
protected:
	void Print(std::ostream& os) const;
public:
	/// Creates an empty pixel
	SingleTPX3Hit();
	/// Copy constructor
	SingleTPX3Hit(SingleTPX3Hit * otherEntry);
	/// Implicit destructor
	~SingleTPX3Hit();
	void JSONify(rapidjson::Writer<rapidjson::StringBuffer> & writer);

	Double_t GetToA() const;
	void SetToA(Double_t ToA);

	Int_t GetToT() const;
	void SetToT(Int_t ToT);

	Short_t GetPixX() const;
	void SetPixX(Short_t PixX);

	Short_t GetPixY() const;
	void SetPixY(Short_t PixY);

	ULong64_t GetSToA() const;
	void SetSToA(ULong64_t);

	UInt_t GetFToA() const;
	void SetFToA(UInt_t);

	ULong64_t GetTriggerNo() const;
	void SetTriggerNo(ULong64_t);
};
