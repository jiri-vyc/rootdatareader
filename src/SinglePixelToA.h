#pragma once
#include "TTreeReaderValue.h"
#include "SingleDataEntry.h"

/**
@brief Class defining the data object containing only single value (of type double) - ToA
*/
class SinglePixelToA: public SingleDataEntry {
private:
	Double_t ToA;
protected:
	void Print(std::ostream& os) const;
public:
	/// Creates an empty pixel
	SinglePixelToA();
	/// Copy constructor
	SinglePixelToA(SinglePixelToA * otherPixel);
	/// Implicit destructor
	~SinglePixelToA();
	void JSONify(rapidjson::Writer<rapidjson::StringBuffer> & writer);

	Double_t GetToA() const;
	void SetToA(Double_t ToA);
};
