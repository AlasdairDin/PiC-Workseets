#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int repeats;
    
    std::cout << "How many times to you want to print Hello\n";
    std::cin >> repeats;

    for(int i = 0; i < repeats; i++){
        printf("Hello\n");
    }
 return 0;
    
};