#include "C:\Users\puurr\Documents\codee\500daysofcode\cpp\projects\randomNumber/randomGeneratorHeader.h"
#include <ctime>
#include <cstdint>
// #include <fstream>
// #include <limits>
// #include <vector>

// algortihm to generate random nums
/*
    - Xnext = ( a * Xcurr + c) % m
    - c and m are realtively prime (they share no common divisors other than 1)
    - a - 1 is divisible by all primes of m (if m is power of 2 then a-1 must be divisible by 2 )
    - if m is the multiple of 4 then a - 1 is must also be multiple of 4
*/

const uint32_t a = 1664525;
const uint32_t c = 1013904223;
const uint64_t m = 1ULL << 32;

uint32_t generateRandomNumber(uint32_t min, uint32_t max)
{
    time_t timestamp = time(NULL) % 10;
    // time(&timestamp);
    uint32_t Xcurr = static_cast<uint32_t>(timestamp), Xnext;
    
    // std::ofstream file("./visualization/file.csv");
    // for (size_t i = 0; i < 100; i++)
    // {
    //     Xnext = ((a * Xcurr ) + c) % m;
    //     Xcurr = Xnext;
    //     Xcurr = min + (Xcurr % (max - min + 1));
    //     file << i << "," << Xcurr << "\n";
    // }
    
    Xnext = ((a * Xcurr ) + c) % m;
    Xnext = min + (Xnext % (max - min + 1));

    return Xnext;
}