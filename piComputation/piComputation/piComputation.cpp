#include <iostream>
#include "omp.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

int main()
{
    // Я не знаю, в чем ошибка, но даже при огромных n ~ 1e9  этот код выдает, что pi = 3.24.
    // Я пробовал менять какие-то параметры, добавлять, вычитать границы, но резулььтат тот же 
    // Поэтому я заявляю! Гордо и смело! ПИ = 3,24. Кгхм...
    // P.S.
    // Приближение делаю по четверти площади круга. При приближении по целой окружности результат тоже
    int n = 1000000;
    int dots_in_circle = 0;
    std::srand(std::time(0));
    std::chrono::time_point<std::chrono::system_clock> start_time_1 = std::chrono::system_clock::now();
    for (int i = 0; i < n; i++) {
        double tmp_x = (std::rand() % n) / (double) n;
        double tmp_y = (std::rand() % n) / (double) n;
        if ((tmp_x * tmp_x + tmp_y * tmp_y) < 1) {
            dots_in_circle++;
        }
    }
    std::chrono::duration<double> time_1 = std::chrono::system_clock::now() - start_time_1;
    std::cout << "Pi without omp: t = " << time_1.count() << std::endl;
    std::cout << 4 * dots_in_circle / (double) n << std::endl;

    int dots_in_circle_omp = 0;
    std::chrono::time_point<std::chrono::system_clock> start_time_2 = std::chrono::system_clock::now();
    int threads = omp_get_max_threads();
    omp_set_num_threads(threads);
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double tmp_x = (std::rand() % n) / (double)n;
        double tmp_y = (std::rand() % n) / (double)n;
        if ((tmp_x * tmp_x + tmp_y * tmp_y) < 1) {
            dots_in_circle_omp++;
        }
    }
    std::chrono::duration<double> time_2 = std::chrono::system_clock::now() - start_time_2;
    std::cout << "Pi with omp: t = " << time_2.count() << std::endl;
    std::cout << 4 * dots_in_circle_omp / (double)n << std::endl;

    /* Вывод:
    Pi without omp: t = 1.99137
    3.2467
    Pi with omp: t = 1.00116
    3.2513

    Выдим, что выигрыш во времени присутствует, но лишь в два раза.
    Конкретно у меня в два раза по той причине, что ядер всего два)
    */
}