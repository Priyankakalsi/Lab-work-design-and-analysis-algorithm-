#include <iostream>


int main() {
    int n, a = 0, b = 1, c, i;
    std::cout << "Enter the number: ";
    std::cin >> n;

    std::cout << a << " " << b << " ";
    i = 1; 
    while (i < n) {
        c = a + b;
        std::cout << c << " ";
        a = b;
        b = c;
        i++;
    }
    
    std::cin.get(); 
    return 0;
}