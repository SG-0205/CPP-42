#include "colors.h"
#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <vector>

int main(void) {
  std::vector<int> int_vector;
  std::list<int> int_list;

  for (int i = 0; i < 20; i++) {
    int_list.push_back(i);
    int_vector.push_back(i);
  }

  std::vector<int>::iterator result_v = easyfind(int_vector, 5);
  std::list<int>::iterator result_l = easyfind(int_list, 5);
  std::cout << "FOUND:\n"
            << "In vector:\t" << *result_v << '\n'
            << "In list:\t" << *result_l << '\n';
  std::cout << '\n';

  try {
    std::vector<int>::iterator bad_v_search = easyfind(int_vector, 100);
    static_cast<void>(bad_v_search);
  } catch (const std::exception &e) {
    std::cerr << "Expected error:\n" << RED << e.what() << RESET << '\n';
  }

  try {
    std::list<int>::iterator bad_l_search = easyfind(int_list, 100);
    static_cast<void>(bad_l_search);
  } catch (const std::exception &e) {
    std::cerr << "Expected error:\n" << RED << e.what() << RESET << '\n';
  }

  return (0);
}
