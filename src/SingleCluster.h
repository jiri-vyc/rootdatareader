#pragma once
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include "SingleDataEntry.h"

/**
@brief Class defining the data object containing values about single hit on the TPX3 detector -ToA, ToT, coordinates, sToA, fToA
*/
class SingleCluster: public SingleDataEntry {
private:
	Int_t clstrSize;
	Double_t * ToA;
	Int_t * ToT;
	Short_t * PixX;
	Short_t * PixY;
    Int_t triggerNo;
protected:
	void Print(std::ostream& os) const;
public:
	/// Creates an empty pixel
	SingleCluster();
	/// Copy constructor
	SingleCluster(SingleCluster * otherEntry);
	/// Implicit destructor
	~SingleCluster();
	void JSONify(rapidjson::Writer<rapidjson::StringBuffer> & writer);

	Int_t GetClstrSize() const;
	void SetClstrSize(Int_t clstrSize);

	Double_t * GetToA() const;
	void SetToA(Double_t * ToA);
	void SetToA(TTreeReaderArray<Double_t> * ToA);

	Int_t * GetToT() const;
	void SetToT(Int_t * ToT);
	void SetToT(TTreeReaderArray<Int_t> * ToT);

	Short_t * GetPixX() const;
	void SetPixX(Short_t * PixX);
	void SetPixX(TTreeReaderArray<Short_t> * PixX);

	Short_t * GetPixY() const;
	void SetPixY(Short_t * PixY);
	void SetPixY(TTreeReaderArray<Short_t> * PixY);

	Int_t GetTriggerNo() const;
	void SetTriggerNo(Int_t triggerNo);
};
