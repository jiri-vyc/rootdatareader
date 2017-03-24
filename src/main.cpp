#include "RootDataReader.h"
#include "OnlyToADataDefinition.h"
#include "SinglePixelToA.h"

#include <typeinfo>
#include <iostream>

using namespace std;

int main(void){
    // ========== TEST =====================
    TFile file("data/testFile1.root");
    TTreeReader reader("Datatree", &file);
    TTreeReaderValue<Double_t> ToA(reader, "ToA");
    cout << "Start." << endl;
    reader.SetEntry(0);
    cout << *ToA << endl;
    cout << "End." << endl;
    // ========== /TEST =====================


    RootDataDefinition * definition;
    RootDataReader * dataReader;
    dataReader = new RootDataReader();
    definition = new OnlyToADataDefinition("data/testFile1.root", "Datatree");

    dataReader->SetDataDefinition(definition);

    cout << dataReader->GetEntryAt(5)->JSONify() << endl;
}