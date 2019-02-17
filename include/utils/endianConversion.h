#include <iostream>

template <typename T>
T SwapEnd(T var)
{
    char* varArray = reinterpret_cast<char*>(&var);
    for(long i = 0; i < static_cast<long>(sizeof(var)/2); i++){
        std::swap(varArray[sizeof(var) - 1 - i],varArray[i]);
    }
    return var;
}