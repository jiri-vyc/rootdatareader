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
Abstract class representing a data entry to be retrieved from the ROOT file.

Specifies its attributes and their types, way how to print them or serialize them.

Can be printed to a stream, can be serialized to JSON.
*/
class SingleDataEntry {
    private:

    protected:
        // Prints the data entry into specified stream
        virtual void print(std::ostream& os) const = 0;
    public:
        SingleDataEntry(){};
        ~SingleDataEntry(){};
        /// Prints the data entry using its print function
        friend std::ostream& operator<< (std::ostream& os, const SingleDataEntry& entry){
            entry.print(os);
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