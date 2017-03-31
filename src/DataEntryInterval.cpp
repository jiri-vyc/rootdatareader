#include "DataEntryInterval.h"

using namespace rapidjson;

DataEntryInterval::~DataEntryInterval(){
	for (unsigned int i = 0; i < this->Size(); i++){
		delete this->At(i);
	}
	this->Clear();
}

void DataEntryInterval::Clear()
{
	this->dataVector.clear();
}

void DataEntryInterval::PopBack()
{
	this->dataVector.pop_back();
}

void DataEntryInterval::PushBack(SingleDataEntry * elem)
{
	this->dataVector.push_back(elem);
}

bool DataEntryInterval::Empty()
{
	return this->dataVector.empty();
}

unsigned int DataEntryInterval::Size()
{
	return this->dataVector.size();
}

SingleDataEntry * DataEntryInterval::Front()
{
	return this->dataVector.front();
}

SingleDataEntry * DataEntryInterval::Back()
{
	return this->dataVector.back();
}

SingleDataEntry * DataEntryInterval::At(unsigned int position)
{
	return this->dataVector.at(position);
}

SingleDataEntry ** DataEntryInterval::ToArray()
{
	unsigned int size = this->Size();
	SingleDataEntry ** dataArray = new SingleDataEntry*[size];
	for (unsigned int i = 0; i < size; i++)
	{
		dataArray[i] = this->At(i);
	}
	return dataArray;
}

void DataEntryInterval::Print()
{
	unsigned int size = this->Size();
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << *this->At(i) << std::endl;
		if (i % 25 == 0 && i / 25 > 0){
			std::cout << "Type <CR> to continue or q to quit ==>" << std::endl;
			if (std::cin.get() == 'q'){
				break;
			}
		}
	}
}

void DataEntryInterval::JSONify(Writer<StringBuffer> & writer)
{
	writer.StartObject();
	writer.Key("Size");
	writer.Uint(this->Size());
	writer.Key("Entries");
	writer.StartArray();
	for (unsigned int i = 0; i < this->Size(); i++)
	{
		this->At(i)->JSONify(writer);
	}
	writer.EndArray();
	writer.EndObject();
}

std::string DataEntryInterval::JSONify()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	this->JSONify(writer);
	return buffer.GetString();
}

