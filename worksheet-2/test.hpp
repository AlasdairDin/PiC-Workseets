#include <iostream>
#include <variant>
#include <iostream>
#include <string>
#include <functional>
#include <iomanip>
#include <limits>

using poly = std::variant<int, float, bool, double, char>;
template<class> inline constexpr bool always_false_v = false;

bool check(poly p,
          std::string t,
          std::function<bool(poly)> theTest){
    
    auto success = false;
    try {
      success = theTest(p);
    }
    catch (const std::bad_variant_access&) {
      std::cout << "\033[33m" << "Looks like your expression evaluates to a ";
      std::visit([](auto&& arg) {
          using T = std::decay_t<decltype(arg)>;
          if constexpr (std::is_same_v<T, int>)
              std::cout << "int with value " << arg << '\n';
          else if constexpr (std::is_same_v<T, float>)
              std::cout << "float with a value of approximately " << arg << "(6 significant digits)"<< '\n';
          else if constexpr (std::is_same_v<T, double>)
              std::cout << "double with a value of approximately " << arg << "(6 significant digits)"<< '\n';
          else if constexpr (std::is_same_v<T, char>)
              std::cout << "char with value " << arg << '\n';
          else if constexpr (std::is_same_v<T, bool>)
              std::cout << "bool with value " << std::boolalpha << arg << '\n';
          else 
              static_assert(always_false_v<T>, "Your expression evaltuates to a type that we weren't expecting.");
      }, p);
      std::cout << "\033[33m" <<"It should evaluate to a value with the type: " << t << "\033[0m" <<'\n';
    }
    return success;
}

void printSuccessCheck(bool success, std::string taskId){
  if(success){
    std::cout << "\033[32m" << taskId << " is correct" << "\033[0m" << '\n';
  }else{
    std::cout << "\033[31m" << taskId << " is currently not correct" << "\033[0m" << '\n';
  }
}

bool compareFloats (float a, float b) {
   float difference = a - b;
   return (difference < std::numeric_limits<float>::epsilon()) &&
    (-difference < std::numeric_limits<float>::epsilon());
}
bool compareDoubles (double a, double b) {
   double difference = a - b;
   return (difference < std::numeric_limits<double>::epsilon()) &&
    (-difference < std::numeric_limits<double>::epsilon());
}
// EXAMPLE 

void testTaskExample(poly p){
  std::cout << "\033[1m\033[35m"  << "---------------------------------------------" << '\n';
  std::cout << "\033[1m\033[33m" << " \t\tWORKSHEET 2" << "\033[0m" <<'\n';
  std::cout << "\033[1m\033[35m"  "---------------------------------------------" << "\033[0m" << '\n';
  std::cout << "Example testing." << '\n';
  auto success = check(p, "int",[](poly p){

      auto i = std::get<int>(p);
      return true;
  });

  if(success){
    std::cout << "The example task is correct" << '\n';
  }else{
    std::cout << "The example task is currently not correct" << '\n';
  }
}

// ,--------.              ,--.         ,--. 
// '--.  .--',--,--. ,---. |  |,-.     /   | 
//    |  |  ' ,-.  |(  .-' |     /     `|  | 
//    |  |  \ '-'  |.-'  `)|  \  \      |  | 
//    `--'   `--`--'`----' `--'`--'     `--' 
/* ------------------------------------------------------------------------------------------------------ */
// 100 / 2
void testTask1_1(poly p){
  const std::string taskNo = "Task1.1";
  std::cout << "\n\n TASK 1" << '\n';
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const auto attempt = std::get<int>(p);

    if (attempt == 100/2) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

void testTask1_2(poly p){
  const std::string taskNo = "Task1.2";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "float",[](poly p){

    const auto attempt = std::get<float>(p);

    if (compareFloats(attempt,2.0f * 0.3f)) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

void testTask1_3(poly p){
  const std::string taskNo = "Task1.3";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "bool",[](poly p){

    const auto attempt = std::get<bool>(p);

    if (attempt == 10 > 5) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

void testTask1_4(poly p){
  const std::string taskNo = "Task1.4";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const auto attempt = std::get<int>(p);

    if (attempt == (10 & 3)) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

void testTask1_5(poly p = false){
  const std::string taskNo = "Task1.5";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "bool",[](poly p){

    const auto attempt = std::get<bool>(p);

    if (attempt){
      std::cout << "\033[35m" <<"Here's the thing! We need to be very careful when using the == operator on floats (and doubles)" << "\033[0m" <<'\n';
      std::cout << "\033[35m" <<"We actually can't be sure this will be consisitent as errors accumlate in these values!" << "\033[0m" <<'\n';
      return true;
    }
    else{
      std::cout << "\033[35m" <<"Here's the thing! We need to be very careful when using the == operator on floats (and doubles)" << "\033[0m" <<'\n';
      std::cout << "\033[35m" <<"We actually can't be sure this will be consisitent as errors accumlate in these values!" << "\033[0m" <<'\n';
      return false;
    }
      
  });

  printSuccessCheck(success, taskNo);
}


// ,--------.              ,--.         ,---.  
// '--.  .--',--,--. ,---. |  |,-.     '.-.  | 
//    |  |  ' ,-.  |(  .-' |     /      .-' .' 
//    |  |  \ '-'  |.-'  `)|  \  \     /   '-. 
//    `--'   `--`--'`----' `--'`--'    '-----' 
/* ------------------------------------------------------------------------------------------------------ */

// Create a floating point variable with a value of 1.0 and add 0.5 
void testTask2_1(poly p=0.0f){
  const std::string taskNo = "Task2.1";
  std::cout << "\n\n TASK 2" << '\n';
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "float",[](poly p){

    const auto attempt = std::get<float>(p);

    if (attempt == 1.5) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}
// Create variables x and y where x is equal to 10 and y is equal to five. Divide x by y.
void testTask2_2(poly p = 0){
 const std::string taskNo = "Task2.2";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const auto attempt = std::get<int>(p);

    if (attempt == 2) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

// Create two variables one with a value true and one with false. 
// Pass the logical 'or' of these variables to the test fucntion.
void testTask2_3(poly p = false){
 const std::string taskNo = "Task2.3";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "bool",[](poly p){

    const auto attempt = std::get<bool>(p);

    if (attempt) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

// Create a single variable called x with a value 200
// Double the variable using the '*=' operator and pass x to the test function
void testTask2_4(poly p = 0){
 const std::string taskNo = "Task2.4";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const auto attempt = std::get<int>(p);

    if (attempt == 400) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}
// Create a single variable called x with a value 1. Increment the variable by 1 and pass x 
// to the test function.
void testTask2_5(poly p = 0){
 const std::string taskNo = "Task2.5";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const auto attempt = std::get<int>(p);

    if (attempt == 2) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}
                                            
// ,--------.              ,--.        ,----.  
// '--.  .--',--,--. ,---. |  |,-.     '.-.  | 
//    |  |  ' ,-.  |(  .-' |     /       .' <  
//    |  |  \ '-'  |.-'  `)|  \  \     /'-'  | 
//    `--'   `--`--'`----' `--'`--'    `----'  
/* ------------------------------------------------------------------------------------------------------ */

// Using integers calculate the area of a square with an edge that has a length of 20 units.
void testTask3_1(poly p = 0){

  const std::string taskNo = "Task3.1";
  std::cout << "\n\n TASK 3" << '\n';
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const int attempt = std::get<int>(p);

    if (attempt == 20 * 20) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

// Calculate the area of a circle with a radius of 2 units with appropriate precission.
void testTask3_2(poly p = 0.0f){

  const std::string taskNo = "Task3.2";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "float",[](poly p){

    const auto attempt = std::get<float>(p);

    float piLow = 3.141592;
    const float answerLower = piLow * 2.0 * 2.0;
    // printf("ans l: %f \n", answerLower);

    float piHigh = 	3.14159265358979323846; //digits as defined in c++
    const float answerHigher = piHigh * 2.0 * 2.0;
    // printf("ans h: %f \n", answerHigher);

    if (attempt >= (answerLower - std::numeric_limits<float>::epsilon()) &&
    attempt <= (answerHigher + std::numeric_limits<float>::epsilon()) ) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}

// Calculate the average (mean) of the values a = 3, b = 7, c = 4
void testTask3_3(poly p = 0.0f){

  const std::string taskNo = "Task3.3";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "float",[](poly p){

    const auto attempt = std::get<float>(p);
    const float answer = (3.0 + 7.0 + 4.0) / 3.0;
    if (compareFloats(attempt, answer)) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}
void testTask3_4(poly p = 0.0){

  const std::string taskNo = "Task3.4";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "double",[](poly p){

    const auto attempt = std::get<double>(p);
    const double light_speed = 2.99792458e8;
    const double lowRes = 2.99792458;

    double high =  2.0 * 300000000.0 * 300000000.0;
    double low = 2.0 * 299792458.0 * 299792458.0;

    if (compareDoubles(attempt, 2.0 * light_speed * light_speed)) return true;
    else {
      if( attempt >= (low - std::numeric_limits<double>::epsilon()) &&
        attempt <= (high + std::numeric_limits<double>::epsilon()) ){
        std::cout << "\033[35m" <<"Close! Improve that accuracy (did you know doubles support scientific notation?) " << "\033[0m" <<'\n';
      }
      return false;
    }
  });

  printSuccessCheck(success, taskNo);
}

//Given x as 256 use a bitwise shift to return the value 64
void testTask3_5(poly p = 0){

  const std::string taskNo = "Task3.5";
  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Testing your solution for "<< taskNo << '\n';
  
  auto success = check(p, "int",[](poly p){

    const auto attempt = std::get<int>(p);

    if (attempt == 256 >> 2) return true;
    else return false;
  });

  printSuccessCheck(success, taskNo);
}