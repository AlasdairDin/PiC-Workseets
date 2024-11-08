#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    for(int i = 1; i < 31; i++){
        if (i % 15 == 0) {
            std::cout << "fizzbuzz, ";
        }
        else if (i % 5 == 0) {
            std::cout << "buzz, ";
        }
        else if ( i % 3 == 0) {
            std::cout << "fizz, ";
        }
        else {
            std::cout << i << ", ";
        }
    }

 return 0;
    
};