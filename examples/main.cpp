#include "../src/RootDataReader.h"
#include "../src/OnlyToADataDefinition.h"
#include "../src/TPX3HitsDataDefinition.h"
#include "../src/ClustersDataDefinition.h"
#include "../src/TPX3HitsInterval.h"
#include "../src/ClustersInterval.h"

#include <typeinfo>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char ** argv){

    std::string fileName;
    if (argc < 2){
        std::cout << "Error: no file specified." << std::endl;
        exit(0);
    }
    fileName = argv[1];
    RootDataDefinition * definition;        // General definition of data 
    RootDataReader * dataReader;            // The reader
    dataReader = new RootDataReader();      // Initialize the reader
    DataEntryInterval * interval;        // General interval


    if (dataReader->Exists(fileName.c_str(), "clusteredData")){
        definition = new ClustersDataDefinition(fileName.c_str(), "clusteredData");  // Assigning concrete data definition
        interval = new ClustersInterval();
    } else if (dataReader->Exists(fileName.c_str(), "Datatree")){
        definition = new TPX3HitsDataDefinition(fileName.c_str(), "Datatree");
        interval = new TPX3HitsInterval();
    } else {
        std::cout << "Error: no appropriate tree found in the root file." << std::endl;
    }

    dataReader->SetDataInterval(interval);
    dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

    cout << dataReader->GetInterval(0, 5)->JSONify() << endl;

    cout << "Done." << endl;

    delete dataReader;
    delete definition;
}