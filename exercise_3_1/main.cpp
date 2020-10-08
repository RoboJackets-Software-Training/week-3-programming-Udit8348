//
// Created by jason on 9/20/20.
//

#include <iostream>

int main() {
  int variable = 10;
  int* variable_ptr = &variable;
  std::cout << "var: " << variable << std::endl;
  // this points out the memory address that it is pointing at
  std::cout << "var_ptr: " << variable_ptr << std::endl;

  // init values
  int a = 5;
  int b = 20;
  int* pa = &a;
  int* pb = &b;
  std::cout << "a: " <<  a << std::endl;
  std::cout << "b: " <<  b << std::endl;
  std::cout << "pa: " <<  pa << std::endl;
  std::cout << "pb: " <<  pb << std::endl;

  // modifications
  a = 10;
  std::cout << "a: " <<  a << std::endl;
  std::cout << "lets compare memory addresses and note that they are the same" << std::endl;
  std::cout << "pa: " <<  pa << std::endl;
  std::cout << "a mem-loc: " <<  &a << std::endl;

  // need to dereference before assigning the new value
  *pa = 30;
  std::cout << "a: " <<  a << std::endl;
  std::cout << "Note how once we change the val using the pointer, its address changes too" << std::endl;
  std::cout << "pa: " <<  pa << std::endl;

  // no need to dereference here since we are dealing with just memory addresses
  pa = &b;
  *pb = 5;
  std::cout << "pa: " <<  pa << std::endl;
  std::cout << "pb: " <<  pb << std::endl;

  std::cout << "swap using only pointers address of and temp" <<  pb << std::endl;
  std::cout << "before a: " <<  a << std::endl;
  std::cout << "before b: " <<  b << std::endl;
  pa = &a;
  pb = &b;
  int temp = *pa;
  a = *pb;
  b = temp;
  std::cout << "after a: " <<  a << std::endl;
  std::cout << "after b: " <<  b << std::endl;
  

  return 0;
}
