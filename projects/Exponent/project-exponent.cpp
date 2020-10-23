/** 
 *  @file    project-exponent.cpp
 *  @author  Alex Rickert
 *  @date    09/29/20
 *  @version 1.0
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <chrono>
#include <math.h>
#include <algorithm>
#include "AlgorithmDesign.h"

int main()
{
  std::srand( std::time(NULL) );
  time_t timer;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  std::chrono::duration< double, std::milli> elapsed;
  elapsed = std::chrono::duration< double, std::milli>::zero();

  std::cout << "Exponential Direct Method\n";
  for(int i=0; i<10; i++)
  {
    int base = (std::rand() % 10);
    int exp = (std::rand() % 10);
    int answer = math::exponent( base, exp );

    std::cout << "\nBase: " << base << " Exp: " << exp << " Answer: " << answer << "\n"; 
  }

  std::cout << "Exponential DAC Method\n";
  for(int i=0; i<10; i++)
  {
    int base = (std::rand() % 10);
    int exp = std::pow(2, (std::rand() % 10) );
    int mod = std::pow(2, 16);

    int answer = math::exponentDAC(base, exp, mod);

    std::cout << "\nBase: " << base << " Exp: " << exp << " Answer: " << answer << "\n"; 
  }
}
