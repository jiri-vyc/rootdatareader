#pragma once
#include <vector>
#include <iostream>
#include "SingleDataEntry.h"

class SingleDataEntry;

/**
@brief The class representing an interval of root data entries. 

It is a decorator over the std::vector class, as it provides the same functionality of the vector collection
and only adds some basic function and JSON serialization
*/
class DataEntryInterval{
private:
	/// The internal standard vector collection, which is being decorated, providing all the base functionality.
	std::vector<SingleDataEntry*> dataVector;
public:
	/// Creates an empty interval of size 0
	DataEntryInterval(){};
	/// Destroys the object and disposes of all the data contained within
	~DataEntryInterval();
	/// Returns all the data from the interval in form of a string-encoded JSON object.
	std::string JSONify();
	/// Sends all the data from interval to the specified JSON Writer object.
	void JSONify(rapidjson::Writer<rapidjson::StringBuffer> & writer);
	/// Browse the data contained within this interval in the same fashion, as ROOT's Browse() function. Shows 25 lines of complete data, then queries user if they want to show more.
	void Print();
	/// Converts to a classic array.
	SingleDataEntry ** ToArray();

	/// std::vector's functionality of the method of the same name
	void PushBack(SingleDataEntry * elem);
	/// std::vector's functionality of the method of the same name
	void PopBack();
	/// std::vector's functionality of the method of the same name
	void Clear();
	/// std::vector's functionality of the method of the same name
	bool Empty();
	/// std::vector's functionality of the method of the same name
	unsigned int Size();	
	/// std::vector's functionality of the method of the same name
	SingleDataEntry * At(unsigned int position);
	/// std::vector's functionality of the method of the same name
	SingleDataEntry * Front();
	/// std::vector's functionality of the method of the same name
	SingleDataEntry * Back();
};