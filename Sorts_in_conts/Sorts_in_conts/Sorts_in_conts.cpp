#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <chrono>
#include <algorithm>

int main()
{
    //#2

    int cont[1000];
    std::vector<int> vect(1000);
    std::list<int> list(1000);
    std::deque<int> deq;
    std::forward_list<int> f_list;

    std::srand(666);
    for (size_t i = 0; i < 1000; i++) {
        int tmp = std::rand();
        cont[i] = tmp;
        vect[i] = tmp;
        list.push_back(tmp);
        deq.push_back(tmp);
        f_list.assign({ tmp });
    }

    std::chrono::time_point<std::chrono::system_clock> start_time_1 = std::chrono::system_clock::now();
    std::sort(cont, cont + 1000);
    std::chrono::duration<double> time_1 = std::chrono::system_clock::now() - start_time_1;

    std::chrono::time_point<std::chrono::system_clock> start_time_2 = std::chrono::system_clock::now();
    std::sort(vect.begin(), vect.end());
    std::chrono::duration<double> time_2 = std::chrono::system_clock::now() - start_time_2;

    std::chrono::time_point<std::chrono::system_clock> start_time_3 = std::chrono::system_clock::now();
    list.sort();
    std::chrono::duration<double> time_3 = std::chrono::system_clock::now() - start_time_3;

    std::chrono::time_point<std::chrono::system_clock> start_time_4 = std::chrono::system_clock::now();
    std::sort(deq.begin(), deq.end());
    std::chrono::duration<double> time_4 = std::chrono::system_clock::now() - start_time_4;

    std::chrono::time_point<std::chrono::system_clock> start_time_5 = std::chrono::system_clock::now();
    f_list.sort();
    std::chrono::duration<double> time_5 = std::chrono::system_clock::now() - start_time_5;

    std::cout << " simple | vector | list | deque | forward_list " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << " " << time_1.count() * 1e6 << " | "
        << " " << time_2.count() * 1e6 << " |"
        << " " << time_3.count() * 1e6 << " |"
        << " " << time_4.count() * 1e6 << " |"
        << " " << time_5.count() * 1e6 << std::endl;
}
