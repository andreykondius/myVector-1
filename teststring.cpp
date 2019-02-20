#include "pch.h"
#include <random>
#include <ctime> 
#include "teststring.hpp"

#include "CStringArray.hpp"

CArray<std::string> Nstring::addRandom_15_low_lat()
{
  std::mt19937 gen(static_cast<unsigned int>(time(0)));
  std::uniform_int_distribution<> uc('a', 'z');
  CArray<std::string> arr;
  for (auto i = 0; i < 15; ++i)
  {
    std::string tempS;
    for (auto j = 0; j < 4; ++j)
      tempS += static_cast<char>(uc(gen));
    arr.push_back(tempS);
  }
  return arr;
}

void Nstring::sortIncrease(
    CArray<std::string> &_val
  )
{
  _val.sort(_val.begin(), _val.end());
}

void Nstring::delWord_a_e(
    CArray<std::string> &_val
  )
{
  unsigned int index = 0;
  while (true)
  {
    if (index == _val.size())
      break;
    bool fBreak = false;
    for (char c='a'; c <= 'e'; ++c)
      if (_val[index].find(c) != std::string::npos)
      {
        fBreak = true;
        _val.erase(index);
        break;				
      }
      if (!fBreak)
        ++index;
  }
}

void Nstring::insRandom_3_ran_pos(
    CArray<std::string> &_val
  )
{
  std::mt19937 gen(static_cast<unsigned int>(time(0)));
  std::uniform_int_distribution<> uc('a', 'z');
  CArray<std::string> arr;
  for (auto i = 0; i < 3; ++i)
  {
    std::string tempS;
    for (auto j = 0; j < 3; ++j)
      tempS += static_cast<char>(uc(gen));
    std::uniform_int_distribution<> uid(0, _val.size() > 0 ? _val.size() - 1 : 0);
    _val.insert(uid(gen), tempS);
  }
}