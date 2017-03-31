# ROOT Data Reader #

Simple reader and (not only JSON) serializer for data in ROOT scientific framework format.

### What is this project good for? ###

This project is aimed for developers who have to or want to work with any arbitrary data stored in CERN's ROOT format without writing complicated proprietary readers, converters and such. This project lets you simply define format of the data, and read them. Without the hassle.

Motivation was increasing popularity of web visualization tools that work with and display scientific data originally stored in the ROOT format. Goal was to provide simple and general way how to read the ROOT data in *any* format and get them to JavaScript in the most convenient format (read JSON).

### Simple usage example ###

~~~~~~~~~~~~~~~{.c}
RootDataDefinition * definition;        // General definition of data 
RootDataReader * dataReader;            // The reader
dataReader = new RootDataReader();      // Initialize
definition = new OnlyToADataDefinition("data/testFile1.root", "Datatree");  // Initializing concrete data definition

dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

cout << dataReader->GetInterval(0, 5)->JSONify() << endl;
~~~~~~~~~~~~~~~
This will nicely, simply print (interval of entries on indexes 0 to 5):
~~~~~~~~~~~~~~~{.js}
{
  "Size":5,
  "Entries":[
    {"ToA":481258120.3125},{"ToA":481258120.3125},{"ToA":481258120.3125},{"ToA":481258120.3125},{"ToA":481258120.3125}
  ]
}
~~~~~~~~~~~~~~~
### So how does it work and how do I use it for my data? ###

There are three main components of the project:

- RootDataReader

     Leave this class as is, use its API to your heart's content. One of its method is RootDataReader::SetDataDefinition(), where you assign the definition, where the data you want to read are and what structure do they have. Its only parameter has to be of type RootDataDefinition.

- RootDataDefinition

     This is where the definition of the data happens. It describes which data, where, and how they are stored in the root file. It describes the types and names of the branches you will be working with. It is an abstract class and only dictates you which methods you have to have in your child class. Extend this class, define the types and names of values you will have in your data (TODO:example). Each of the values represent a single value stored in the tree branch and will be automatically filled. Then, implement the GetEntry() method. In this method, manipulate the values from the branches that you specified as you want and save the result into object of type SingleDataEntry and return it.

- SingleDataEntry

     This is the class which represents one single data object you want to be working with. It doesn't have to correspond 1:1 with the data stored in root files and defined in RootDataDefinition. You have stored 2 parts of the desired object's single attribute in 2 separate branches? No problem, combine them in defined way in the RootDataDefinition and store them in single value in SingleDataEntry. This is the resulting object (representing real one) that you want to be manipulating, visualizing, researching. No matter how the data are physically stored in the files. It can be complex particle cluster, a frame, or a simple object with only one value (as in TODO:example SinglePixelToA). To get such object, extend this class(SingleDataEntry), define your concrete entry's attributes, implement your own Getters and Setters if needed and implement the virtual methods Print() and JSONify(), specifying, how you want to print/serialize your values (you can see TODO:example here).

     You can have data stored in two different ways (different trees, different branches), but you want to get the same resulting data from them? No problem either, you can have several different RootDataDefinitions, which define and manipulate the data in different way, but stores them into single (same) SingleDataEntry. The other way around? Also no problem, define two RootDataDefinitions to read the exact same data, but save them into different (SingleDataEntry) objects.

### So what can I do with it then? ###

For example this:

~~~~~~~~~~~~~~~{.c}
dataReader = new RootDataReader();      // Initialize
definition = new TPX3HitDataDefinition("data/testFile1.root", "Datatree");  // Initializing concrete data definition

dataReader->SetDataDefinition(definition);  // Tell the reader to use this data definition

cout << dataReader->GetEntry(0)->JSONify() << endl;
~~~~~~~~~~~~~~~

Prints:

~~~~~~~~~~~~~~~{.js}
{"index": 0, "PixX": 250, "PixY": 154, "ToT": 332, "ToA":481258120.3125, "triggerNo": 0}
~~~~~~~~~~~~~~~

And adding this:

~~~~~~~~~~~~~~~{.c}
definition2 = new TPX3ClusterDataDefinition("data/testFile1.root", "Clustertree");
dataReader->SetDataDefinition(definition2);

cout << dataReader->GetEntry(0)->JSONify() << endl;
~~~~~~~~~~~~~~~

Prints:

~~~~~~~~~~~~~~~{.js}
{
    "clstrSize": 3, 
    "PixX": [250, 102, 51], 
    "PixY": [154, 252, 189], 
    "ToT": [332, 12, 105], 
    "ToA": [481258120.3125, 481258200.625, 481258220.0], 
    "clstrType": "Small Blob", 
    "clstrVolCentroidX": 110, 
    "clstrVolCentroidY": 188
}
~~~~~~~~~~~~~~~

### How to set it up and use it? ###

You need only few prerequisites:

- ROOT Installed
- g++ 4.9+
- make

There is a Makefile included in the project, so all you have to do to compile the example is to run `make` in the project's folder.

When you add your classes and implementations, add them to the Makefile:

~~~~~~~~~~~~~~~{.make}
rootdatareader: main.o reader.o definition.o pixeltoa.o definitiontoa.o interval.o mynewclass.o
mynewclass.o:
	$(CC) $(CFLAGS) src/MyNewClass.cpp -o build/MyNewClass.o
~~~~~~~~~~~~~~~

### Contribution guidelines ###

* TODO

### Who do I talk to? ###

[jiri.vyc@gmail.com](mailto:jiri.vyc@gmail.com)