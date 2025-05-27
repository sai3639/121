using std:: cout;
using std:: endl;
#include <stdexcept>

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

// int SumBetween(int low, int high) {
//   int value = 0;
//   // if (low > high){
//   //   throw std::invalid_argument("inputs are out of order");
//   // }
//   // if low bound is negative - change bounds
//   if (low < 0 && high > 0){
//     low = (low*(-1)) +1;

//   }

//   // if (low > INT32_MAX - high){
//   //   throw std::overflow_error("integer overflow");
//   //}
//   // if (low < high && low > 0 && high > INT32_MAX - low){
//   //   throw std::overflow_error("integer overflow");
//   // }
//   // else if (high < low && high > 0 && low > INT32_MAX - high){
//   //   throw std::overflow_error("integer overflow");
//   // }
//   // else if ( low < 0 && high < INT32_MIN - low){
//   //   throw std::overflow_error("integer overflow");
//   // }
//   for (int n = low; n <= high; n++) {
//     value += n;
//     if (low > 0 && high > 0 && value < 0){
//       throw std::overflow_error("integer overflow");
      
//     }
//     // if(low < 0 && high < 0 && value > 0){
//     //   throw std::overflow_error("integer overflow");
//     //   break;
//     // }
//   }
//   return value;
// }

int Product(int a, int b) {
  
  int product;
  product = a * b;

  // if (a!=0 && a < INT32_MAX/b){
  //   cout << INT32_MAX/b << endl;
  //   cout << a << " " << b << endl;
  // }
  if (((a > 0 && b > 0) && (product < 0))){
    throw std::overflow_error("integer overflow");
  }
  if ((a < 0 && b < 0) && (product < 0)){
    throw std::overflow_error("integer overflow");
  }
  if ((a < 0 && b > 0) && (product > 0)){
    throw std::overflow_error("integer overflow");
  }
  if ((a > 0 && b < 0 ) && (product > 0)){
    throw std::overflow_error("integer overflow");
  }


  else if (( a != 0 && b!=0))
  {
    if(product/a == b && product/b == a){

    product = product;
    }
  }
  else if (a == 0 || b == 0){
    product = 0;
     
  }

  // else if (a != 0 && a < INT32_MAX/b){
  //   throw std::overflow_error("integer overflow");
  // }
  // else if (b!= 0 && b < INT32_MAX/a){
  //   throw std::overflow_error("integer overflow");
  // }

  return product;

}