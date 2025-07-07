#pragma once

template <typename T> void swap(T &first_elem, T &second_elem) {
  T swap = first_elem;
  first_elem = second_elem;
  second_elem = swap;
};

template <typename T> T &min(T &first_elem, T &second_elem) {
  return (first_elem < second_elem ? first_elem : second_elem);
};

template <typename T> T &max(T &first_elem, T &second_elem) {
  return (first_elem > second_elem ? first_elem : second_elem);
};
