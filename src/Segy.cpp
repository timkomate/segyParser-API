#include "../include/Segy.h"

Segy::Segy(){}

Segy::~Segy() = default;

void Segy::openSegyFile(char * fileName){
    this->fileName = fileName;
    ifs.open(this->fileName, std::ifstream::in | std::ifstream::binary);
    calcFileSize();
}

void Segy::parseSegyFile(){
    char textHeader[3200];
    TraceHeader tmpTH;
    ifs.read(textHeader,sizeof(textHeader));
    ifs.read(reinterpret_cast<char *>(&binaryHeader), sizeof(binaryHeader));
    int trace[SwapEnd(binaryHeader.samplesPerTrace)];
    while (fileSize > ifs.tellg()){
        ifs.read(reinterpret_cast<char *>(&tmpTH), sizeof(tmpTH));
        ifs.read(reinterpret_cast<char *>(&trace), sizeof(trace));
        traceHeaders.push_back(tmpTH);
        tmpTH = {};

    }
}

void Segy::closeSegyFile(){
    ifs.close();
}

void Segy::printAllTraceHeader(){
    for(size_t i = 0; i<traceHeaders.size(); i++) {
        printTraceHeader(i);
    }
}

void Segy::calcFileSize(){
    ifs.seekg(0, ifs.end);
    fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
}
