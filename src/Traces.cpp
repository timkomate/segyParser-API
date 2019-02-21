#include "../include/Traces.h"

Traces::Traces(){
    
}

Traces::Traces(int size){
    traces.resize(size);
}

void Traces::resize(int size){
    traces.resize(size);
}

void Traces::add(std::vector<int> input){
    traces.push_back(input);
    size++;
}