#include "Classes.hpp"
#include "functions.hpp"

int main(void) {
  Base *random_instance = generate();

  identify(random_instance);
  identify(*random_instance);

  delete random_instance;

  return (0);
}
