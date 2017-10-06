#include "RootDataReader.h"
#include "OnlyToADataDefinition.h"
#include "TPX3HitsDataDefinition.h"
#include "ClustersDataDefinition.h"
#include "TPX3HitsInterval.h"

#include <typeinfo>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(void){

    RootDataDefinition * definition;        // General definition of data 
    RootDataReader * dataReader;            // The reader
    dataReader = new RootDataReader();      // Initialize
    definition = new ClustersDataDefinition("data/L07W005_Bias150V.root", "clusteredData");  // Assigning concrete data definition
    //definition = new TPX3HitsDataDefinition("data/testFile1.root", "Datatree");
    //DataEntryInterval * interval = new TPX3HitsInterval();

    //dataReader->SetDataInterval(interval);

    dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

    cout << dataReader->GetEntryAt(0)->JSONify() << endl;
    //cout << dataReader->GetInterval(0, 5)->SetDatatype("TPX3Hits")->JSONify() << endl;
    //cout << dataReader->GetIntervalBySearch<Double_t>(0, 481258120.3125)->SetDatatype("TPX3Hits")->JSONify() << endl;

    cout << "Done." << endl;

    delete dataReader;
    delete definition;
}