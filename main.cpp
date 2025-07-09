//using example
#include "ForwardList.h"
#include <string>
#include <iostream>

int main() {
    ForwardList<std::string> list;
    list.push_front("Bob");
    list.push_front("Alice");
    list.push_front("Eve");

    std::cout << "List contents (via iterator): ";
    for (const auto& name : list) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    list.print(); 
}


