#pragma once
#include "TTreeReaderValue.h"
#include "SingleDataEntry.h"

/**
* Represents one individial pixel hit with only one (double) ToA value
*/
class SinglePixelToA: public SingleDataEntry {
private:
	Double_t ToA;
protected:
	void print(std::ostream& os) const;
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
