#include <stdexcept>
#include <iostream>
using std::cout, std::endl;

int Largest(int a, int b, int c) {
  int d = 0;
  
    if (a < 0 && b < 0 && c< 0){
    d = a;
    if (d < b){
      d = b;
    }
    if ( d < c){
      d = c;
    }
    }

  else{
    if (a > d) {
      d = a;
      } 
    if (b > d) {
      d = b;
    } 
    if (c > d) {
      d = c;
    }
  }

  

  return d;
}
bool SumIsEven(int a, int b) {
  if((a+b)%2 != 0){
    return false;
  }
  else{
    return true;
  }
}

int BoxesNeeded(int apples) {
  if ((apples>=20) && (apples%20 ==0)){
    apples = apples/20;
  }
  else if ((apples > 0) && (apples <20)){
    apples = 1;
  }
  else if ((apples > 20) && (apples%20 != 0)){
    apples = (apples/20) + 1;

  }
  else{
    apples=0;
  }
  return apples;
}

bool SmarterSection(double A_correct, double A_total, double B_correct, double B_total) {
  bool grade;
  double A = A_correct/A_total;
  double B = B_correct/B_total;
  if ((A_correct < 0 || A_total <= 0 || B_correct < 0 || B_total <= 0) || (A_correct > A_total || B_correct > B_total)){
    throw std::invalid_argument("received negative input");
  }
  else if (A>B){
    grade = true;
  }
  else{
    grade = false;
  }

  return grade;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if ((pizzas >= 10 && pizzas <= 20) && is_weekend == false) {
    return true;
  }
  if (is_weekend == true && pizzas >= 10) {
    return true;
  }
  else{
    return false;
  }
}


int SumBetween(int low, int high) {
  if (low > high)
          throw std::invalid_argument("Lower bound must be less than the higher bound");

     if (low == high)
          return low;

     if (low == high * -1)
          return 0;

     if (low + high == 1)
          return high;

     if (low + high == -1)
          return low;

     if (low < 0 && high > 0) {
          low *= -1;
          if (low > high) {
               int temp = low;
               low = high;
               high = temp;
          }
          low++;
     }

     if (low == high)
          return low;

     if (low == high * -1)
          return 0;

     int value = 0;
     for (int n = low; n <= high; n++) {
          if (value > INT32_MAX - n && n > 0)
               throw std::overflow_error("Sum overflowed");
          if (value < INT32_MIN - n && n < 0)
               throw std::overflow_error("Sum underflowed");
          value += n;
     }
     return value;
}

int Product(int a, int b) {
    if ((a == INT32_MIN && b == -1) || (a == -1 && b == INT32_MIN))
          throw std::overflow_error("Product overflowed");

     if (a < 0 && b < 0) {
          a *= -1;
          b *= -1;
     }

     if (b > 0) {
          if (a > INT32_MAX / b)
               throw std::overflow_error("Product overflowed");
          if (a < INT32_MIN / b)
               throw std::overflow_error("Product underflowed");
     } else if (b < 0) {
          if (a < INT32_MAX / b)
               throw std::overflow_error("Product overflowed");
          if (a > INT32_MIN / b)
               throw std::overflow_error("Product underflowed");
     }

     return a * b;
}