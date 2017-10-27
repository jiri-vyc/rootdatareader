#include "../src/RootDataReader.h"
#include "../src/OnlyToADataDefinition.h"
#include "../src/TPX3HitsDataDefinition.h"
#include "../src/ClustersDataDefinition.h"
#include "../src/TPX3HitsInterval.h"

#include <typeinfo>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(void){

    RootDataDefinition * definition;        // General definition of data 
    RootDataReader * dataReader;            // The reader
    dataReader = new RootDataReader();      // Initialize the reader
    // DataEntryInterval * interval;        // General interval


    if (dataReader->Exists("data/L07W005_Bias150V.root", "clusteredData")){
        definition = new ClustersDataDefinition("data/L07W005_Bias150V.root", "clusteredData");  // Assigning concrete data definition
    } else if (dataReader->Exists("data/L07W005_Bias150V.root", "Datatree")){
        definition = new TPX3HitsDataDefinition("data/L07W005_Bias150V.root", "Datatree");
        interval = new TPX3HitsInterval();
    } else {
        std::cout << "Error: no appropriate tree found in the root file." << std::endl;
    }

    // dataReader->SetDataInterval(interval);
    dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

    cout << dataReader->GetInterval(0, 5)->JSONify() << endl;

    cout << "Done." << endl;

    delete dataReader;
    delete definition;
}