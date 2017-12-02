#pragma once
#include "DataEntryInterval.h"
#include "SingleCluster.h"

class ClustersInterval: public DataEntryInterval{
    private:
        unsigned int HitsCount(){
            unsigned int sum = 0;
            for (unsigned int i = 0; i < this->Size(); i++)
            {
                sum += ( (SingleCluster*)this->At(i) )->GetClstrSize();
            }
            return sum;
        }
        unsigned int SumEnergy()
        {
            return 42;
        }
    public:
        void JSONify(Writer<StringBuffer> & writer)
        {
            writer.StartObject();
            writer.Key("Datatype");
            writer.String("TPX3Clusters");
            writer.Key("TriggerCount");
            writer.Uint(1);
            writer.Key("HitsCount");
            writer.Uint(this->HitsCount());
            writer.Key("Size");
            writer.Uint(this->Size());
            writer.Key("SumEnergy");
            writer.Uint(this->SumEnergy());
            writer.Key("StartTime");
            writer.Double(0);
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