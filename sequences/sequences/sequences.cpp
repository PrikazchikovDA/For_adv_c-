#include <iostream>
#include <stdlib.h>
#include <ctime> std::rand(time(0));
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_set>

// Я понимаю, что алгоритм можно оптимизировать и оптимизировать, но мне лень
bool is_prime(int n) {
    for (int i = 2; i < std::sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    // 1
    int n = 15;
    std::list<int> p1;
    for (int i = 0; i < n; i++) {
        int tmp = std::rand() % 10 + 1;
        p1.push_back(tmp);
    }
    std::copy(p1.cbegin(), p1.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 2
    for (int i = 0; i < 1; i++) {
        int tmp;
        std::cin >> tmp;
        p1.push_back(tmp);
        //std::copy(p1.cend(), std::istream_iterator<int>(std::cin));
    }
    std::copy(p1.cbegin(), p1.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 3
    std::vector<int> tmp1(p1.cbegin(), p1.cend());
    std::random_shuffle(tmp1.begin(), tmp1.end());
    std::copy(tmp1.begin(), tmp1.end(), p1.begin());
    std::copy(p1.cbegin(), p1.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 4
    std::unordered_set<int> tmp2(p1.begin(), p1.end());
    p1.assign(tmp2.begin(), tmp2.end());
    //p1.unique();
    std::copy(p1.cbegin(), p1.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 5
    int count = 0;
    for (auto it = p1.begin(); it != p1.end(); ++it) {
        if (*it % 2 == 1) {
            count++;
        }
    }
    std::cout << "Number of odds: " << count << std::endl;

    // 6
    std::list<int>::const_iterator it;
    it = std::min_element(p1.begin(), p1.end());
    std::cout << "Min element is " << *it << std::endl;
    it = std::max_element(p1.begin(), p1.end());
    std::cout << "Max element is " << *it << std::endl;

    // 7
    for (auto it = p1.begin(); it != p1.end(); ++it) {
        if (!is_prime(*it)) {
            continue;
        }
        else {
            std::cout << "Prime is " << *it << std::endl;
            break;
        }
    }

    // 8
    for (auto it = p1.begin(); it != p1.end(); ++it) {
        p1.insert(it, (*it) * (*it));
    }
    std::copy(p1.cbegin(), p1.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 9
    std::list<int> p2;
    int p1_size = p1.size();
    //std::cout << p1_size << "\n";
    for (int i = 0; i < p1_size; i++) {
        int tmp = std::rand() % 10 + 1;
        p2.push_back(tmp);
    }
    std::copy(p2.begin(), p2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 10
    int sum_p2 = 0;
    for (auto it = p2.begin(); it != p2.end(); ++it) {
        sum_p2 += *it;
    }
    std::cout << "Sum of elements in p2: " << sum_p2 << std::endl;

    // 11
    std::vector<int> tmp3(p2.begin(), p2.end());
    tmp3.erase(tmp3.begin(), tmp3.begin() + 4);
    tmp3.insert(tmp3.begin(), 4, 1);
    p2.assign(tmp3.begin(), tmp3.end());
    //p2.insert(p2.begin(), 4, 1);
    std::copy(p2.cbegin(), p2.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 12
    std::list<int> p3;
    auto it1 = p1.begin();
    auto it2 = p2.begin();
    for (int i = 0; i < p1_size; i++, it1++, it2++) {
        int tmp = *it1 - *it2;
        p3.push_back(tmp);
    }
    std::copy(p3.begin(), p3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 13
    for (auto it = p3.begin(); it != p3.end(); ++it) {
        if (*it < 0) {
            p3.erase(it--);
            p3.emplace(it, 0);
        }
    }
    std::copy(p3.begin(), p3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 14
    for (auto it = p3.begin(); it != p3.end(); ++it) {
        if (*it == 0) {
            p3.erase(it--);
        }
    }
    std::copy(p3.begin(), p3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 15
    std::reverse(p3.begin(), p3.end());
    std::copy(p3.begin(), p3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    //16
    std::vector<int> tmp6(p3.begin(), p3.end());
    std::sort(tmp6.begin(), tmp6.end());
    std::copy(tmp6.end() - 3, tmp6.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    //17
    std::vector<int> tmp4(p1.begin(), p1.end());
    std::sort(tmp4.begin(), tmp4.end());
    p1.assign(tmp4.begin(), tmp4.end());
    std::copy(p1.begin(), p1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    std::vector<int> tmp5(p2.begin(), p2.end());
    std::sort(tmp5.begin(), tmp5.end());
    p2.assign(tmp5.begin(), tmp5.end());
    std::copy(p2.begin(), p2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 18
    std::list<int> p4, p1_, p2_;
    p1_.assign(p1.begin(), p1.end());
    p2_.assign(p2.begin(), p2.end());
    p4.merge(p1_);
    p4.merge(p2_);
    std::copy(p4.begin(), p4.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // 19
    int diap = 0;
    for (auto it = p4.begin(); it != p4.end(); ++it) {
        if (*it == 1) {
            diap++;
        }
        else {
            break;
        }
    }
    std::cout << "Diaposon for ordered insertion is: [0, " << diap << "]\n";

    // 20
    std::copy(p1.begin(), p1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(p2.begin(), p2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(p3.begin(), p3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(p4.begin(), p4.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}