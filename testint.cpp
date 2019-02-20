#include "pch.h"
#include "iostream"
#include <random>
#include <ctime>  
#include "testint.hpp"

#include "carray.ipp"

CArray<int> NInt::addRandom_20_0_100()
{
  std::mt19937 gen(static_cast<unsigned int>(time(0)));
  std::uniform_int_distribution<> uid(0, 100);
  CArray<int> arr;
  for (auto i = 0; i < 20; ++i)
    arr.push_back(uid(gen));
  return arr;
}

void NInt::sortIncrease(
    CArray<int> &_val
  )
{	
	_val.sort(_val.begin(), _val.end());
}

void NInt::delEverySecond(
    CArray<int> &_val
  )
{
  CArray<int> temp;
  for (int *p = _val.begin(); p != _val.end(); p = p+2)
    temp.push_back(*p);
  _val = temp;
}

void NInt::insRandom_10_0_100_ran_pos(
    CArray<int> &_val
  )
{
  std::mt19937 gen(static_cast<unsigned int>(time(0)));
  std::uniform_int_distribution<> el(0, 100);	
  for (auto i = 0; i < 10; ++i)
  {
    std::uniform_int_distribution<> uid(0, _val.size() > 0 ? _val.size() - 1 : 0);
    _val.insert(uid(gen), el(gen));
  }
}
