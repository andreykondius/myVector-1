#pragma once
#include "pch.h"
#include "iostream"
#include "testint.hpp"
#include "teststring.hpp"

int main()
{
  std::cout << "Start testing with integers." << std::endl;
  CArray<int> iArr;

  std::cout << "Add random int 0..100:" << std::endl;
  iArr = NInt::addRandom_20_0_100();
  iArr.printData();

  std::cout << "Sort increase:" << std::endl;
  NInt::sortIncrease(iArr);
  iArr.printData();

  std::cout << "Delete every second element:" << std::endl;
  NInt::delEverySecond(iArr);
  iArr.printData();

  std::cout << "Insert random 10 element (0..100) at a random position:" << std::endl;
  NInt::insRandom_10_0_100_ran_pos(iArr);
  iArr.printData();

  std::cout << "Clear container:" << std::endl;
  iArr.clear();
  iArr.printData();
  std::cout << "The container cleared" << std::endl;


  std::cout << "Start testing with std::string." << std::endl;
  CArray<std::string> sArr;

  std::cout << "Add random 15 words:" << std::endl;
  sArr = Nstring::addRandom_15_low_lat();
  sArr.printData();

  std::cout << "Sort increase:" << std::endl;
  Nstring::sortIncrease(sArr);
  sArr.printData();

  std::cout << "Removing word containing the letters from a to e:" << std::endl;
  Nstring::delWord_a_e(sArr);
  sArr.printData();

  std::cout << "Insert 3 new randomly selected words at random positions:" << std::endl;
  Nstring::insRandom_3_ran_pos(sArr);
  sArr.printData();
  
  std::cout << "End of tests." << std::endl;
}
