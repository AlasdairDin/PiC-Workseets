#include "stack.hpp"

// Task 1 - Implement Stack class. Note you will need to work in both the stack.hpp & stack.cpp
// You should add declarations (such as member variables) to the .hpp and provide function definitions in the .cpp
// Below the functions you will require are implemented, but you shoudl feel free to add others if you wish (this is not required)

bool Stack::push(int value) { 
    if (top < MAX_SIZE)
        {stack[top] = value;
        ++top;
        return true;
        } 
        return false;
    }

bool Stack::pop(int * value) {  
    if (top == 0){
        return false;
    }
    --top;
    *value = stack[top];
    return true;
}

unsigned int Stack::size() const { return top; }

bool Stack::full() const {
    if (top == MAX_SIZE){
        return true;
    }
    return false;
    }

bool Stack::empty() const { 
    if (top == 0){
        return true;
    }
    return false; 
    }

void Stack::clear() {
    top = 0;
}
