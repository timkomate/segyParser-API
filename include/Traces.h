//
// Created by Mate Timko 2018.02.16
//

#ifndef SEGY_TRACE_H
#define SEGY_TRACE_H

#include "./utils/endianConversion.h"
#include <iostream>
#include <vector>
#include <fstream>

class Traces{
    public:
        Traces();
        Traces(int size);
        void resize(int size);
        void add(std::vector<int> input);
        ~Traces();
    private:
        std::vector<std::vector<int>> traces;
        size_t size = 0;
};


#endif // SEGY_TRACE_H