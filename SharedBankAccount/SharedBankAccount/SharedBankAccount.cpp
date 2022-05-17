#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <vector>

#define ll long long
#define shared std::shared_ptr<BankAccount>

class HumanBeing {
private:
    bool access;
public:
    std::string name;

    HumanBeing(std::string name, bool access=false) {
        this->name = name;
        this->access = access;
    }

    const std::string getname() {
        return this->name;
    }

    void changename(std::string NewName) {
        this->name = NewName;
    }
    
    bool haveAccess() {
        return access;
    }

    void giveAccess(HumanBeing& oth) {
        if (oth.haveAccess()) {
            this->access = true;
        }
    }

    void retractAccess(HumanBeing& oth) {
        if (oth.haveAccess()) {
            this->access = false;
        }
    }
};

class BankAccount {
private:
    std::string number;
    ll money;
public:
    BankAccount(std::string number, ll money = -50) : number(number), money(money)  {}

    const std::string getNumber() {
        return this->number;
    }

    void addMoney(ll money, HumanBeing &oth) {
        if (oth.haveAccess()) {
            std::cout << "Access granted" << std::endl;
            this->money += money;
            std::cout << "Succesfully added " << money << " dollars!" << std::endl;
        }
        else {
            std::cout << "Access denied" << std::endl;
        }
    }

    void takeMoney(ll money, HumanBeing& oth) {
        if (oth.haveAccess()) {
            std::cout << "Access granted" << std::endl;
            this->money -= money;
            std::cout << "Succesfully took out " << money << " dollars!" << std::endl;
        }
        else {
            std::cout << "Access denied" << std::endl;
        }
    }

    ll getConteined(HumanBeing& oth) {\
        if (oth.haveAccess()) {
            std::cout << "Access granted" << std::endl;
            return money;
        }
        else {
            std::cout << "Access denied" << std::endl;
            return -1;
        }
    }
};

int main()
{
    //p.addMoney(100, true);

    //std::cout << p.getConteined() << std::endl;
    //std::cout << p.getNumber() << std::endl;

    //BankAccount* shared = new BankAccount("fkhfk");
    //std::shared_ptr<BankAccount> Ivan(shared);

    // Назвал так намеренно ;)
    // Первое содержит людей, второе ссылки на возможные банковские ячейки
    //std::map<std::string, HumanBeing> humans;
    //std::map<std::string, std::shared_ptr<BankAccount>> BankCells;
    //std::string sometext;
    //std::cin >> sometext;
    //while (sometext != "terminate") {
    //    std::cin >> sometext;
    //    if (sometext == "add") {
    //        std::cin >> sometext;
    //        if (sometext == "human") {
    //            std::cin >> sometext;
    //            humans[sometext] = HumanBeing(sometext);
    //            std::cout << 2 << std::endl;
    //        }
    //    }
    //    std::cin >> sometext;
    //}
    //HumanBeing p = ;
    //std::cout << humans["ivan"].getname() << std::endl;

    // КОММЕНТАРИЙ:
    // У меня была глобальная цель, создать что-то вроде
    // Git-Bash по стилю того, как вводить/выводить команды
    // и описывать, что происходит, но в итоге стало тупо
    // лень проводить отладку того, чтобы программа верно
    // считывала команды и пр. Поэтому я предлагаю пример 
    // того, как можно работать со всей этой прелестью из
    // кода непосредственно. Как-то так...

    // P.S. Кстати, не совсем ясно, как именно здесь можно
    // использовать самого человека, т.е. HumanBeing, как
    // оно есть

    // P.P.S. В ходе написания кода ниже, придумал, как
    // можно здесь использовать людей в приколах с
    // доступом. Скучно, но всё же

    // Создадим некоторый банковский аккаунт с двумя владельцами
    BankAccount* Shared = new BankAccount("some_string_of_digits");
    HumanBeing Ivan("Ivan", true);
    shared ivan(Shared);
    HumanBeing Petr("Petr");
    shared petr(ivan);

    // Петя посмотрит, сколько же денег на счёте
    // Минус за открытие и обслуживание
    std::cout << petr.get()->getNumber() << std::endl;
    std::cout << petr.get()->getConteined(Petr) << std::endl;
    // У-у-пс. У Пети нет доступа..
    // Дадим ему доступ. Зачем Ваня это сделал?
    Petr.giveAccess(Ivan);
    std::cout << petr.get()->getConteined(Petr) << std::endl;

    // Ваня решил положить 10 000 долларов на счёт
    ivan.get()->addMoney(10000, Ivan);
    std::cout << ivan.get()->getConteined(Ivan) << std::endl;

    // Петя посмотрел, сколько денег на счёте, обрадовался и отнял
    // у Вани доступ к карте. (Да, нужно было внимательнее читать
    // пользовательское соглашение)
    std::cout << petr.get()->getConteined(Petr) << std::endl;
    std::cout << "Wow!!!" << std::endl;
    Ivan.retractAccess(Petr);
    petr.get()->takeMoney(9500, Petr);
    std::cout << ivan.get()->getConteined(Ivan) << std::endl;

    // Вот такая вот трогательная и грустная история
}
