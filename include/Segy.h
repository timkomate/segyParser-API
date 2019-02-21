//
// Created by Mate Timko 2018.02.16
//

#ifndef SEGY_SEGY_H
#define SEGY_SEGY_H

#include "BinaryHeader.h"
#include "TraceHeader.h"
#include "./utils/endianConversion.h"
#include <iostream>
#include <vector>
#include <fstream>

class Segy{
 public:
    Segy();
    ~Segy();
    void openSegyFile(char * filename);
    void parseSegyFile();
    void closeSegyFile();
    void printBinaryHeader();
    void printTraceHeader(unsigned int i);
    void printTraceHeader();
    void printAllTraceHeader();
    void printInfo();
    void printTrace(int traceNum);

    void readTrace(int sampleSize);
 private:
   void calcFileSize(); 
   std::ifstream ifs;
   char * fileName;
   BinaryHeader binaryHeader;
   std::vector<TraceHeader> traceHeaders;
   int fileSize;
   std::vector<std::vector<float>> traces;
    
};


#endif // SEGY_SEGY_H