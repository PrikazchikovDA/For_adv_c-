#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    // Что такое тип изменения и какую функцию для этого нужно вызвать, я не нашел :-)
    std::string path;
    std::cin >> path;
    for (const auto& entry : fs::directory_iterator(path))
        std::cout << entry.path()
        << " | " << entry.last_wtite_time() 
        << std::endl;
}