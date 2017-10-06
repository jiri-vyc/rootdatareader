# The variable CC will be the compiler to use.
CC=g++
# The variable CFLAGS will be the options to pass to the compiler.
CFLAGS=-Wall -pedantic -ggdb `root-config --cflags` -c

all: rootdatareader
rootdatareader: main.o reader.o definition.o pixeltoa.o definitiontoa.o interval.o tpx3hit.o definitiontpx3hit.o cluster.o definitionCluters.o
	$(CC) `root-config --libs --glibs` -lTreePlayer -o release/rootdatareader.o build/*.o
main.o:
	$(CC) $(CFLAGS) src/main.cpp -o build/main.o
reader.o:
	$(CC) $(CFLAGS) src/RootDataReader.cpp -o build/RootDataReader.o
definition.o:
	$(CC) $(CFLAGS) src/RootDataDefinition.cpp -o build/RootDataDefinition.o
pixeltoa.o:
	$(CC) $(CFLAGS) src/SinglePixelToA.cpp -o build/SinglePixelToA.o
definitiontoa.o:
	$(CC) $(CFLAGS) src/OnlyToADataDefinition.cpp -o build/OnlyToADataDefinition.o
tpx3hit.o:
	$(CC) $(CFLAGS) src/SingleTPX3Hit.cpp -o build/SingleTPX3Hit.o
definitiontpx3hit.o:
	$(CC) $(CFLAGS) src/TPX3HitsDataDefinition.cpp -o build/TPX3HitsDataDefinition.o
cluster.o:
	$(CC) $(CFLAGS) src/SingleCluster.cpp -o build/SingleCluster.o
definitionCluters.o:
	$(CC) $(CFLAGS) src/ClustersDataDefinition.cpp -o build/ClustersDataDefinition.o
interval.o:
	$(CC) $(CFLAGS) src/DataEntryInterval.cpp -o build/DataEntryInterval.o
clean:
	rm -f release/*.o build/*.o