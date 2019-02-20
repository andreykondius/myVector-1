#pragma once
#include <algorithm>

template<typename TData>
class CArray
{
  unsigned int len;
  TData *data;
public:
  CArray();
  CArray(
	  const CArray& _array
  );
  CArray(
    const TData* _val,
    const int _len
  );
  ~CArray();
  void push_back(
    const TData& _value
  );
  void insert(
    unsigned int _index,
    const TData& _value
  );
void erase(
    unsigned int _index
  );
void clear();
unsigned int size() const;
TData& operator[](
    unsigned int _index
  );
const TData& operator[](
    unsigned int _index
  ) const;
CArray<TData> &operator=(
    CArray<TData> _val
  );
bool operator==(
    const CArray<TData>&
  )const; 
bool operator!=(
    const CArray<TData> &_val
  )const;

TData* begin()
{
  return data;
}
const TData* begin() const
{
  return data;
}

TData* end()
{
  return len > 0 ? &data[len] : nullptr;
}

const TData* end() const
{
  return len > 0 ? &data[len] : nullptr;
}

void sort(
    TData *_beg,
    TData* _end
  );

void printData();

};

template<>
CArray<std::string> &CArray<std::string>::operator=(
    CArray<std::string> _val
  );

template<>
void CArray<std::string>::push_back(
    const std::string& _value
  );

template<>
void CArray<std::string>::insert(
    unsigned int _index,
    const std::string& _value
  );

template<>
void CArray<std::string>::erase(
    unsigned int _index
  );

template<>
void CArray<std::string>::clear();

template<>
void CArray<std::string>::sort(
    std::string *_beg,
    std::string *_end
  );

template<>
void CArray<std::string>::printData();

#include "carray.ipp"

