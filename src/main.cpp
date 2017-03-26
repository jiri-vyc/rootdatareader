#include "RootDataReader.h"
#include "OnlyToADataDefinition.h"
#include "SinglePixelToA.h"

#include <typeinfo>
#include <iostream>

using namespace std;

int main(void){

    RootDataDefinition * definition;
    RootDataReader * dataReader;
    dataReader = new RootDataReader();
    definition = new OnlyToADataDefinition("data/testFile1.root", "Datatree");

    dataReader->SetDataDefinition(definition);

    cout << dataReader->GetInterval(0, 5)->JSONify() << endl;
}