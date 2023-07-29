#include "stack.h"

#include <iostream>

int main() {
    Stack<int> s;

    std::cout << "s: " << s << "\n";

    s.push(1);
    std::cout << "s: " << s << "\n";

    s.push(42);
    std::cout << "s: " << s << "\n";

    s.push(10);
    std::cout << "s: " << s << "\n";

    s.pop();
    std::cout << "s: " << s << "\n";
    
    s.pop();
    std::cout << "s: " << s << "\n";

    s.pop();
    std::cout << "s: " << s << "\n";

    std::cout << "s is empty: " << std::boolalpha << s.empty() << "\n";


}