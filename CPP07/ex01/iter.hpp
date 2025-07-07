#pragma once

#include <cstddef>
template <typename Array, typename Function>
void iter(Array *array, size_t lenght, Function function) {
  for (size_t i = 0; i < lenght; i++)
    function(array[i]);
}
