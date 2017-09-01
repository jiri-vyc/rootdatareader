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
    definition = new OnlyToADataDefinition("data/testFile1.root", "Datatree");  // Assigning concrete data definition
    //definition = new TPX3HitsDataDefinition("data/testFile1.root", "Datatree");

    dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

    cout << dataReader->GetInterval(0, 5)->JSONify() << endl;

    Double_t search = 10481258117.1876;
    Long64_t found = dataReader->GetStartingIndex<Double_t>(search);
    cout << "Index: " << found << endl;

    cout << "On index " << found << ": " << std::setprecision(15) << *dataReader->GetEntryAt(found) << endl;
    cout << "On index " << found+1 << ": " << std::setprecision(15) << *dataReader->GetEntryAt(found+1) << endl;

    cout << "Done." << endl;


    delete dataReader;
    delete definition;
}