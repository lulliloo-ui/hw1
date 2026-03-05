#include<iostream>

template< class T >
T* merge(const T* const * a, size_t sa, const size_t * sai, size_t index, size_t& counter, T* c)
{
  size_t new_counter = 0;
  try {
    for (size_t i = 0; i < sa; ++i) {
      if (sai[i] > index) {
        c[new_counter++] = a[i][index];
      }
    }
  } catch (...) {
    std::cerr << "Error\n";
    counter += new_counter;
    throw;
  }
  counter += new_counter;
  c += new_counter;
  return c;
}


template< class T >
T* merge(const T* const * a, size_t sa, const size_t * sai, T* c)
{
  size_t max = 0;
  for(size_t i = 0; i < sa; ++i) {
    if(max < sai[i]) {
      max = sai[i];
    }
  }

  T* end = c;
  size_t counter = 0;
  try {
    for(size_t i = 0; i < max; ++i) {
      end = merge(a, sa, sai, i, counter, end);
    }
  } catch(...) {
    return c + counter;
  }
  return end;
}


int main()
{
  int arr1[] = {1, 4, 7};
  int arr2[] = {2, 5, 8};
  int arr3[] = {3, 6, 9};
  
  const int* arrays[] = {arr1, arr2, arr3};
  size_t sizes[] = {3, 3, 3};
  
  int result[9] = {0};
  
  int* end = merge(arrays, 3, sizes, result);
  size_t size = end - result;
  std::cout << result[1];
  for (size_t i = 1; i < size; ++i) {
    std::cout << " " << result[i];
  }
  std::cout << "\n";
  
  return 0;
}