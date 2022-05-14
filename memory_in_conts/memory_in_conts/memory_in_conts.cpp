#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <forward_list>
#include <limits>
#include <stdlib.h>
#include <chrono>
#include <algorithm>

#define ull unsigned long long

int main()
{
    //#1
    // testing the vector

    std::vector<size_t> V;
    //V.reserve(1e9);
    std::cout << "#1" << std::endl;
    size_t mem = 0;
    int n = 0;
    for (size_t i = 0; i < std::numeric_limits<size_t>::max(); i++) {
            V.push_back(i);
            if (mem != V.capacity()) {
                std::cout << n <<": " << V.capacity() << std::endl;
                mem = V.capacity();
                n++;
            }
    }
    /*/out:
    #1
        0: 1
        1 : 2
        2 : 3
        3 : 4
        4 : 6
        5 : 9
        6 : 13
        7 : 19
        8 : 28
        9 : 42
        10 : 63
        11 : 94
        12 : 141
        13 : 211
        14 : 316
        15 : 474
        16 : 711
        17 : 1066
        18 : 1599
        19 : 2398
        20 : 3597
        21 : 5395
        22 : 8092
        23 : 12138
        24 : 18207
        25 : 27310
        26 : 40965
        27 : 61447
        28 : 92170
        29 : 138255
        30 : 207382
        31 : 311073
        32 : 466609
        33 : 699913
        34 : 1049869
        35 : 1574803
        36 : 2362204
        37 : 3543306
        38 : 5314959
        39 : 7972438
        40 : 11958657
        41 : 17937985
        42 : 26906977
        43 : 40360465
        44 : 60540697
        45 : 90811045
        46: 136216567
        47: 204324850
        48: 306487275
        49: 459730912
        50: 689596368
        51: 1034394552
    If reserved without limits:
    #1
        0: 1000000000

    Судя по всему, дальше ОС выделет память в жестком диске, потому что работать начинает
    работать кратко-кратно дольше, не пропорционально выделяемой памяти
    */
}