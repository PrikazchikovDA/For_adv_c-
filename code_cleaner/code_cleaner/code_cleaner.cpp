#include <fstream> 
#include <iostream>
#include <string>

int main()
{
    std::ifstream in("for_homework.txt");
    std::ofstream out("result.txt");
    std::string line, type_1 = "//", type_2 = "/*", type_3 = "*/";// , type_4 = '\"\M\"';
    size_t simp, comp_open, comp_close;
    int count = 0;
    while (in.eof() != 1)
    {
        getline(in, line);
        while ((line.find(type_1) != std::string::npos) 
            || (line.find(type_2) != std::string::npos) || (count == 1)) {
            simp = line.find(type_1);
            comp_open = line.find(type_2);
            comp_close = line.find(type_3);
            if (count == 0){
                if (comp_open < simp) {
                    if ((comp_close != std::string::npos)) {
                        line.erase(comp_open, comp_close - 2);
                    } else {
                        line.erase(line.begin() + comp_open, line.end());
                        count = 1;
                        break;
                    }
                } else {
                    line.erase(simp);
                    break;
                }
            } else {
                if (comp_close != std::string::npos) {
                    line.erase(0, comp_close + 2);
                    count = 0;
                } else {
                    line.erase(0);
                    break;
                }
            }
        }
        if (line.empty() != 1)
            out << line << std::endl;
    }
    in.close();
    out.close();
    system("result.txt");
    return 0;
}