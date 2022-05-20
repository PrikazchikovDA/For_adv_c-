#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>

using nlohmann::json;

struct person {
    std::string name;
    std::string family_name;
    unsigned int age;
};

namespace ns {
    void to_json(json& j, const person& p) {
        j = json{ {"name", p.name}, {"family name", p.family_name}, {"age", p.age} };
    }

    void from_json(const json& j, person& p) {
        j.at("name").get_to(p.name);
        j.at("address").get_to(p.family_name);
        j.at("age").get_to(p.age);
    }
}

int main()
{
    person p;
    std::cout << "Enter first name: ";
    std::cin >> p.name;
    std::cout << "Enter second name: ";
    std::cin >> p.family_name;
    std::cout << "Enter age: ";
    std::cin >> p.age;
    json obj = {
        {"name", p.name},
        {"family name", p.family_name},
        {"age", p.age}
    };

    std::ofstream file("person.json");
    file << obj;
}