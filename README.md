# ROOT Data Reader #

Simple reader and (not only JSON) serializer for data in ROOT scientific framework format.

### What is this project good for? ###

This project is aimed for developers who have to or want to work with any arbitrary data stored in CERN's ROOT format without writing complicated proprietary readers, converters and such. This project lets you simply define format of the data, and read them. Without the hassle.

Motivation was increasing popularity of web visualization tools that work with and display scientific data originally stored in the ROOT format. Goal was to provide simple and general way how to read the ROOT data in *any* format and get them to JavaScript in the most convenient format (read JSON).

### Usage ###

```
    RootDataDefinition * definition;
    RootDataReader * dataReader;
    dataReader = new RootDataReader();
    definition = new OnlyToADataDefinition("data/testFile1.root", "Datatree");

    dataReader->SetDataDefinition(definition);

    cout << dataReader->GetInterval(0, 5)->JSONify() << endl;
```
This will nicely, simply print:
```
{
  "Size":5,
  "Entries":[
    {"ToA":481258120.3125},{"ToA":481258120.3125},{"ToA":481258120.3125},{"ToA":481258120.3125},{"ToA":48125812
0.3125}
  ]
}
```

### How to set it up and use it? ###

* TODO

### Contribution guidelines ###

* TODO

### Who do I talk to? ###

[jiri.vyc@gmail.com](mailto:jiri.vyc@gmail.com)