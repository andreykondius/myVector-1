#pragma once
//#include "carray.hpp"
#include <iostream>

auto copyStr = [](
    const std::string *_src,
    const unsigned int _beg,
    const unsigned int _end,
    std::string *_dst,
    const unsigned int _start = 0
  )
{
  if (_src == nullptr)
    return;
  unsigned int index = _start;
  for (unsigned int i = _beg; i < _end; ++i)
    _dst[index++] = _src[i];
};

template<>
CArray<std::string> &CArray<std::string>::operator=(
    CArray<std::string> _val
  )
{
  if (this == &_val)
    return *this;
  len = _val.len;
  if (data != nullptr)
    delete[]data;
  data = new std::string[len];
  copyStr(_val.data, 0, _val.size(), data);
  return *this;
}

template<>
void CArray<std::string>::push_back(
    const std::string& _value
  )
{
  std::string *p = new std::string[len];
  if (len > 0)
    copyStr(data, 0, len, p);
  if (data != nullptr)
	  delete[]data;
  len++;
  data = new std::string[len];
  if (len > 1)
    copyStr(p, 0, len-1, data);
  data[len - 1] = _value;
  delete[]p;
}

template<>
void CArray<std::string>::insert(
    unsigned int _index,
    const std::string& _value
  )
{
  if (_index < 0 || _index >= len)
    return;
  std::string *p = new std::string[len];
  copyStr(data, 0, len, p);
  if (data != nullptr)
    delete[]data;
  len++;
  data = new std::string[len];
  copyStr(p, 0, _index, data);
  data[_index] = _value;
  copyStr(p, _index, len-1, data, _index+1);
  delete[]p;
}

template<>
void CArray<std::string>::erase(
    unsigned int _index
  )
{
  if (_index < 0 || _index >= len)
    return;
  std::string *p = new std::string[len];
  copyStr(data, 0, len, p);
  if (data != nullptr)
    delete[]data;
  data = new std::string[len - 1];
  copyStr(p, 0, _index, data);
  copyStr(p, _index+1, len, data, _index);
  len--;
  delete[]p;
}

template<>
void CArray<std::string>::clear()
{
	len = 0;
	if (data != nullptr)
		delete[]data;
	data = nullptr;
}

template<>
void CArray<std::string>::sort(
    std::string *_beg,
    std::string *_end
  )
{
  for (unsigned int i = 0; i < len-1; ++i)
    for (unsigned int j = i+1; j < len; ++j)
      if (strcmp(data[i].c_str(), data[j].c_str()) > 0)
        swap(data[i], data[j]);
}

template<>
void CArray<std::string>::printData()
{
  unsigned int row = 0;
  for (unsigned int i = 0; i < len; ++i)
  {
    ++row;
    std::cout << "row " << row << " : " << data[i].c_str() << std::endl;
  }
  std::cout << std::endl;
}
