#include "test.hpp"

int main(){                                          

{//------------------------------------------------------------------------------------------------------ 
// Here is an example of how a complete task will look:                                         
  int value = 0;
  // Assign value to the the expression:
  // 10 + 10
  value = 10 + 10;

  testTaskExample(value);
/* ------------------------------------------------------------------------------------------------------ */ }{

// ,--------.              ,--.         ,--. 
// '--.  .--',--,--. ,---. |  |,-.     /   | 
//    |  |  ' ,-.  |(  .-' |     /     `|  | 
//    |  |  \ '-'  |.-'  `)|  \  \      |  | 
//    `--'   `--`--'`----' `--'`--'     `--' 
/* ------------------------------------------------------------------------------------------------------ */ }{
  int value = 0;
  // Assign value to the integer expression:
  // 100 / 2
  value = 100 / 2;
 
  testTask1_1(value);
/* ------------------------------------------------------------------------------------------------------ */ }{
  float value = 0.0;
  // Assign a float value to the result of the expression:
  // 2.0 * 0.3 
  value = 2.0 * 0.3;
  testTask1_2(value);
/* ------------------------------------------------------------------------------------------------------ */ }{
  bool value = false;
  // assign value to the boolean result of an expression that checks if 10 is greater than 5.  
  value = 10 > 5;
  testTask1_3(value);
/* ------------------------------------------------------------------------------------------------------ */ }{
  int value = 0;
  // assign value to the result of an expression that calculates the bitwise 'and' of 10 and 3.  
  value = 10 & 3;
  testTask1_4(value);
/* ------------------------------------------------------------------------------------------------------ */ }{
  bool value = false;
  // assign value to the boolean result of comparing if variables 'a' and 'b' are equal:
  int a = false;
  int b = false;
  if(a==b){
    value=true;
  }
  else value=false;


  // Then pass value into this function:
  testTask1_5(value);
/* ------------------------------------------------------------------------------------------------------ */ }{
// ,--------.              ,--.         ,---.  
// '--.  .--',--,--. ,---. |  |,-.     '.-.  |
//    |  |  ' ,-.  |(  .-' |     /      .-' .' 
//    |  |  \ '-'  |.-'  `)|  \  \     /   '-. 
//    `--'   `--`--'`----' `--'`--'    '-----' 
/* ------------------------------------------------------------------------------------------------------ */

        /* 
        In task 2, you will need to declare your own variables! Feel free to declare any variables 
        you require and think about the types you are using. 
        
        You will need to pass your values to the test function. You are welcome to declare new variables 
        to this, or write your expressions directly as a function argument
        */

/* ------------------------------------------------------------------------------------------------------ */ }{                                            
// 2.1 Create a floating point variable with a value of 1.0 and add 0.5 
// Pass this new value to the test function.
float value = 1;
float answer = value + 0.5;
  testTask2_1(answer);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 2.2 Create variables x and y where x is equal to 10 and y is equal to five. Divide x by y.
  int x = 10;
  int y = 5;
  int answer = x / y; 

  testTask2_2(answer);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 2.3 Create two variables one with a value true and one with false. 
// Pass the logical 'or' of these variables to the test fucntion.
  bool x = true;
  bool y = false;
  bool answer = x || y;
  testTask2_3(answer);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 2.4 Create a single variable called x with a value 200
// Double the variable using the '*=' operator and pass x to the test function.
  int x = 200;
  x *= 2;

  testTask2_4(x);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 2.5 Create a single variable called x with a value 1. Increment the variable by 1 and pass x 
// to the test function.
  int x = 1;
  x++;

  testTask2_5(x);

/* ------------------------------------------------------------------------------------------------------ */ }{
// ,--------.              ,--.        ,----.  
// '--.  .--',--,--. ,---. |  |,-.     '.-.  | 
//    |  |  ' ,-.  |(  .-' |     /       .' <  
//    |  |  \ '-'  |.-'  `)|  \  \     /'-'  | 
//    `--'   `--`--'`----' `--'`--'    `----'  
// 3.1 Using integers calculate the area of a square with an edge that has a length of 20 units.

  int area = 20 * 20;
  testTask3_1(area);
/* ------------------------------------------------------------------------------------------------------ */ }{                                   
// 3.2 Calculate the area of a circle with a radius of 2 units with appropriate precission.
  float pi = 3.141592;
  float radius = 2.0;
  float area = pi * radius * radius;
  testTask3_2(area);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 3.3 Calculate the average (mean) of the values a = 3, b = 7, c = 4
  float a = 3.0;
  float b = 7.0;
  float c = 4.0;
  float mean = (a + b + c) / 3;
  testTask3_3(mean);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 3.4 Using the Einsteins famous E=MC^2 calculate E where M is 2
  double C = 299792458;
  double M = 2;
  double E = M * C * C;
  testTask3_4(E);
/* ------------------------------------------------------------------------------------------------------ */ }{
// 3.5 Given x as 256 use a bitwise shift to return the value 64
  int answer = 0;
  int x = 256;
  int y = x >> 2;
  testTask3_5(y);
/* ------------------------------------------------------------------------------------------------------ */ }                                          
// ,--------.              ,--.          ,---. 
// '--.  .--',--,--. ,---. |  |,-.      /    | 
//    |  |  ' ,-.  |(  .-' |     /     /  '  | 
//    |  |  \ '-'  |.-'  `)|  \  \     '--|  | 
//    `--'   `--`--'`----' `--'`--'       `--' 
                               
  return 0;
}
