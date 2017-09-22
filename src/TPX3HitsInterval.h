#pragma once
#include "DataEntryInterval.h"
#include "SingleTPX3Hit.h"

class TPX3HitsInterval: public DataEntryInterval{
    private:
        unsigned int SumEnergy()
        {
            unsigned int sum = 0;
            for (unsigned int i = 0; i < this->Size(); i++)
            {
                sum += ( (SingleTPX3Hit*)this->At(i) )->GetToT();
            }
            return sum;
        }
    public:
        void JSONify(Writer<StringBuffer> & writer)
        {
            writer.StartObject();
            writer.Key("Datatype");
            writer.String("TPX3Hits");
            writer.Key("Size");
            writer.Uint(this->Size());
            writer.Key("SumEnergy");
            writer.Uint(this->SumEnergy());
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