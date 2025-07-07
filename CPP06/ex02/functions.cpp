#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  srand(std::time(0));

  unsigned int seed = rand() % 4;

  switch (seed) {
  case (0):
    return (new A());
    break;
  case (1):
    return (new B());
    break;
  case (2):
    return (new C());
    break;
  default:
    return (new A());
  }
}

void identify(Base *p) {
  if (!p)
    return;

  if (dynamic_cast<A *>(p))
    std::cout << "Instance is of class A" << '\n';
  else if (dynamic_cast<B *>(p))
    std::cout << "Instance is of class B" << '\n';
  else if (dynamic_cast<C *>(p))
    std::cout << "Instance is of class C" << '\n';
}

void identify(Base &p) { identify(&p); }
