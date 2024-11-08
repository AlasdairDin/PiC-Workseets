#include "rpn.hpp"
#include "stack.hpp"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
// Task 2 - you need to implement the following rpn_eval function
// This function shoudl evaluate RPN expressions
// You should use your stack class to help evaluate these expressions
bool isOperator(char op){
  if (op == '+' || op == '-' || op == '/' || op == '*'){
    return true;
  }
  else return false;
}

Stack s;
string rpn_eval(std::string expr)
{
  string token = "";
  for (int i = 0; i != expr.size(); ++i)
  {
    if (expr[i] != ' ')
    {
      token += expr[i];
    }
    else
    {
      if (isOperator(token[0]))
      {
        if (token[0] == '+')
        {
          int x;
          int y;
          s.pop(&x);
          s.pop(&y);
          s.push(x + y);
        }
        else if (token[0] == '*')
        {
          int x;
          int y;
          s.pop(&x);
          s.pop(&y);
          s.push(x * y);
        }
        else if (token[0] == '-')
        {
          int x;
          int y;
          s.pop(&x);
          s.pop(&y);
          s.push(x - y);
        }
        else if (token[0] == '/')
        {
          int x;
          int y;
          s.pop(&x);
          s.pop(&y);
          s.push(x / y);
        }
        token = "";
      }
      else
      {
        s.push(atoi(token.c_str()));
        token = "";
      }
    }
  }
  int answer;
  s.pop(&answer);
  string result = to_string(answer);
  return result;
}
