#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    string name;
    
    std::cout << "Hello what is your name?\n";
    std::cin >> name;

    std::cout << "Your name is " + name;
    
};