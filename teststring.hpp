#pragma once

#include "CArray.hpp"

namespace Nstring
{
  CArray<std::string> addRandom_15_low_lat();
  void sortIncrease(
    CArray<std::string> &_val
  );
  void delWord_a_e(
    CArray<std::string> &_val
  );
  void insRandom_3_ran_pos(
    CArray<std::string> &_val
  );
}
