#include <iostream>
#include "./include/TraceHeader.h"
#include "./include/Segy.h"

int main(int argc, char ** argv){
    Segy s;
    s.openSegyFile(argv[1]);
    s.parseSegyFile();
    s.printBinaryHeader();
    s.printAllTraceHeader();
    s.printInfo();
    s.closeSegyFile();
}