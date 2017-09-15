#pragma once
#include "DataEntryInterval.h"

class TPX3HitsInterval: public DataEntryInterval{
    public:
        void JSONify(Writer<StringBuffer> & writer)
        {
            writer.StartObject();
            writer.Key("Datatype");
            writer.String("TPX3Hits");
            writer.Key("Size");
            writer.Uint(this->Size());
            writer.Key("Pixels");
            writer.StartArray();
            for (unsigned int i = 0; i < this->Size(); i++)
            {
                this->At(i)->JSONify(writer);
            }
            writer.EndArray();
            writer.EndObject();
        }
};