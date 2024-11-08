#pragma once

class Stack {
private:
    static const int MAX_SIZE = 256;
    int top = 0;
    int stack[MAX_SIZE];
public:
    /**
     * push value onto stack
     * @param  value value to push on stack
     * @return       true, if successful, otherwise false
     */
    bool push(int value);

    /**
     * pop value of stack
     * @param  value set to value popped, if successful
     * @return       true, if pop successful, otherwise false
     */
    bool pop(int * value);

    /**
     * calculate size of stack
     * @return returns current size of stack
     */
    unsigned int size() const;

    /**
     * test if stack full
     * @return true if full, otherwise false
     */
    bool full() const;

    /**
     * is stack empty
     * @return true, if stack empty, otherwise false
     */
    bool empty() const;

    /**
     * clear stack
     */
    void clear();

    /** 
     * friend function for testing - you can ignore this one!
     */ 
    friend bool test_stack();
};
