#include "RootDataReader.h"
#include "OnlyToADataDefinition.h"

#include <typeinfo>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(void){

    RootDataDefinition * definition;        // General definition of data 
    RootDataReader * dataReader;            // The reader
    dataReader = new RootDataReader();      // Initialize
    definition = new OnlyToADataDefinition("data/testFile1.root", "Datatree");  // Assigning concrete data definition

    dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

    cout << dataReader->GetInterval(0, 10)->JSONify() << endl;

    cout << "Done." << endl;


    delete dataReader;
    delete definition;
}