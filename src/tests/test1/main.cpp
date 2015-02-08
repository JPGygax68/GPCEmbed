#include <iostream>

#include "data.dat.h"

int main(int argc, char *argv[])
{
    for (auto i = 0U; i < sizeof(data)/sizeof(data[0]); i ++) {
        std::cout << i << ": " << data[i] << std::endl;
    }
    
    return 1;
}