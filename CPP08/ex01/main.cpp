#include "Span.hpp"
#include "colors.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int main(void) {
  Span test_empty;
  Span short_test(5);
  Span big_test(1e7);
  Span no_data_span(5);

  try {
    test_empty.addNumber(5);
  } catch (const std::exception &e) {
    std::cerr << "Expected error:\n" << RED << e.what() << RESET << '\n';
  }

  try {
    no_data_span.longestSpan();
  } catch (const std::exception &e) {
    std::cerr << "Expected error:\n" << RED << e.what() << RESET << '\n';
  }

  short_test.addNumber(-4);
  short_test.addNumber(4);
  short_test.addNumber(29);
  short_test.addNumber(88);
  short_test.addNumber(99);
  try {
    short_test.addNumber(0);
  } catch (const std::exception &e) {
    std::cerr << "Expected error:\n" << RED << e.what() << RESET << '\n';
  }

  std::cout << "ShortestSpan (Span(5)) " << short_test.shortestSpan() << '\n';
  std::cout << "LongestSpan (Span(5)) " << short_test.longestSpan() << '\n';

  srand(time(0));

  try {
    for (size_t i = 0; i < 10000000; i++) {
      big_test.addNumber(rand());
    }
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << '\n';
  }

  std::cout << "ShortestSpan (Span(1e7)) " << big_test.shortestSpan() << '\n';
  std::cout << "LongestSpan (Span(1e7)) " << big_test.longestSpan() << '\n';

  std::cout << "Subject tests:\n";
  Span sp = Span(8);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::vector<int> buffer;
  buffer.push_back(1);
  buffer.push_back(2);
  buffer.push_back(7);

  sp.addNumbers(buffer.begin(), buffer.end());
  sp.printContent();
}
