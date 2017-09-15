#include "RootDataReader.h"
#include "OnlyToADataDefinition.h"
#include "TPX3HitsDataDefinition.h"

#include <typeinfo>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(void){

    RootDataDefinition * definition;        // General definition of data 
    RootDataReader * dataReader;            // The reader
    dataReader = new RootDataReader();      // Initialize
    definition = new TPX3HitsDataDefinition("data/L07W005_Bias150V.root", "clusteredData");  // Assigning concrete data definition
    //definition = new TPX3HitsDataDefinition("data/testFile1.root", "Datatree");

    dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

    cout << dataReader->GetInterval(0, 1)->SetDatatype("TPX3Hits")->JSONify() << endl;

    cout << "Done." << endl;

    delete dataReader;
    delete definition;
}