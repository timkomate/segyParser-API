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
    binaryHeader = SwapEnd(binaryHeader);
    float trace [SwapEnd(binaryHeader.samplesPerTrace)];
    float tmp;
    while (fileSize > ifs.tellg()){
        float ibm_ = 0;
        
        ifs.read(reinterpret_cast<char *>(&tmpTH), sizeof(tmpTH));
        //readTrace(SwapEnd(binaryHeader.samplesPerTrace));
        ifs.read(reinterpret_cast<char *>(&trace), sizeof(trace));
        //traces.push_back(trace);
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

void Segy::readTrace(int sampleSize){
    float tmp;
    std::vector<float> tmpVector;
    for (int i = 0; i<sampleSize; i++){
        ifs.read(reinterpret_cast<char *>(&tmp), sizeof(tmp));
        //std::cout << tmp << std::endl;
        std::cout << std::hex << (int&)(tmp) << std::endl;
        tmpVector.push_back(tmp);
    }
    traces.push_back(tmpVector);
}
