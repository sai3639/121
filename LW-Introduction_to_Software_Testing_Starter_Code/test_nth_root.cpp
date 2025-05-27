#include <iostream>
#include <cmath>
#include "./nth_root.h"
#include "nth_root.cpp"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        nth_root(2, 1);
        nth_root(5,3);
        nth_root(2,4);
        try{
            if (nth_root(0, 1)){
                throw std::domain_error("domain error");
            }
        }
        catch(std::domain_error& excpt){
            
        }

        nth_root(4,-2);
        nth_root(-3,0);
        nth_root(1,3);
        nth_root(-1,5);
        nth_root(-3,4);
        nth_root(-6,2);
        nth_root(-5,2);
        nth_root(6,3);
        nth_root(5,0);
        nth_root(3,1);
        nth_root(5,-2);
        nth_root(5,7);
        nth_root(4,2.2);

    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
