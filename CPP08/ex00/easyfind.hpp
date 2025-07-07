#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &container, int n) {

  typename T::iterator it = find(container.begin(), container.end(), n);
  if (it == container.end())
    throw std::runtime_error("easyfind::search unsuccessful");

  return (it);
}
