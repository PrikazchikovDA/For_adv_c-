#include <iostream>
#include <fstream>
#include <string>

std::string read_line_n(const std::string& name, int n) {
    std::string  line;
    std::ifstream f(name);

    while (f.eof() != 1 && (n > 0)) {
        getline(f, line);
        --n;
    }

    return line;
}



int main(void) {
    std::string filename;
    std::cin >> filename;
    std::string line = read_line_n("some_rows.txt", 2);
    std::cout << line << std::endl;
}