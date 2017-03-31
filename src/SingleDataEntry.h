#pragma once
#ifdef _WIN32
#include "include\rapidjson\writer.h"
#include "include\rapidjson\prettywriter.h"
#else
#include "include/rapidjson/writer.h"
#include "include/rapidjson/prettywriter.h"
#endif

using namespace rapidjson;
/**
@brief Abstract class representing a data object to be retrieved from the ROOT file.

Represents the result object we want to work with after retrieving the data from ROOT files. Specifies the object's attributes and their types, way how to print them or serialize them. The whole object can be printed to a stream, can be serialized to JSON.
*/
class SingleDataEntry {
    private:

    protected:
        /// Prints the data entry into specified stream
        virtual void Print(std::ostream& os) const = 0;
    public:
        /// Implicit base constructor, does nothing
        SingleDataEntry(){};
        /// Virtual destructor. Each derived class has to dispose of their own garbage
        virtual ~SingleDataEntry(){};
        /// Prints the data entry using its print function
        friend std::ostream& operator<< (std::ostream& os, const SingleDataEntry& entry){
            entry.Print(os);
            return os;
        }
        /// Writes the JSON representation of this one single entry into the specified JSON writer.
	    virtual void JSONify(rapidjson::Writer<rapidjson::StringBuffer> & writer) = 0;
        /// Returns JSON string serialization of this object
        std::string JSONify(){
            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            this->JSONify(writer);
            return buffer.GetString();
        }
};