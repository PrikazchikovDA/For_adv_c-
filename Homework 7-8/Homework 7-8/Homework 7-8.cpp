#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>

int main()
{
    // #1

    // Создаём праочку массивов
    const int n = 100000;
    int cont[100000];
    std::vector<int> vect;
    std::set<int> all;
    
    // Генерируем случайные числа для подстановки их позднее в set & vector
    std::srand(666);
    for (size_t i = 0; i < n; i++) {
        int tmp = std::rand();
        cont[i] = tmp;
    }

    // Проверяем vector
    std::chrono::time_point<std::chrono::system_clock> start_time_vec = std::chrono::system_clock::now();
    for (size_t i = 0; i < n; i++) {
        vect.push_back(cont[i]);
    }
    std::sort(vect.begin(), vect.end());
    std::chrono::duration<double> time_vec = std::chrono::system_clock::now() - start_time_vec;

    // Проверяем set
    std::chrono::time_point<std::chrono::system_clock> start_time_set = std::chrono::system_clock::now();
    for (size_t i = 0; i < n; i++) {
        all.insert(cont[i]);
    }
    std::chrono::duration<double> time_set = std::chrono::system_clock::now() - start_time_set;

    // Выводим результаты
    std::cout << " vector | set" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << " " << time_vec.count() << " | "
        << " " << time_set.count() << std::endl;

    // После многократных запусков очевидно, что отличие примерно в три раза!
    // В смысле, vector  в три раза быстрее
}