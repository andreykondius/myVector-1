#pragma once
#include <ostream>

template<typename TData>
CArray<TData>::CArray()
{
  len = 0;
  data = nullptr;
}

template<typename TData>
CArray<TData>::~CArray()
{
  if (data)
    delete[]data;
  data = nullptr;
}

template<typename TData>
CArray<TData>::CArray(
    const CArray& _array
  )
{
  len = _array.len;
  data = new TData[len];
  std::copy(_array.data, _array.data + _array.len, data);
}

template<typename TData>
CArray<TData>::CArray(
    const TData* _data,
    const int _len
  )
{
  len = _len;
  data = new TData[len];
  std::copy(_data, _data + len, data);
}

template<typename TData>
void CArray<TData>::push_back(
    const TData& _value
  )
{
  TData *p = new TData[len];
  if (len > 0)
    std::copy(data, data + len, p);
  if (data)
    delete[]data;
  len++;
  data = new TData[len];
  if (len > 1)
    std::copy(p, p + len - 1, data);
  data[len - 1] = _value;
  delete[]p;
}

template<typename TData>
void CArray<TData>::insert(
    unsigned int _index,
    const TData& _value
  )
{
  if (_index < 0 || _index >= len)
    return;
  TData *p = new TData[len];
  if (len > 0)
    std::copy(data, data + len, p);
  if (data)
    delete[]data;
  len++;
  data = new TData[len];
  std::copy(p, p + _index, data);
  data[_index] = _value;
  std::copy(p + _index, p + len, data + _index + 1);
  delete[]p;
}

template<typename TData>
void CArray<TData>::erase(
    unsigned int _index
  )
{
  if (_index < 0 || _index >= len)
    return;
  TData *p = new TData[len];
  std::copy(data, data + len, p);
  if (data)
    delete[]data;
  data = new TData[len - 1];
  std::copy(p, p + _index, data);
  std::copy(p + _index + 1, p + len, data + _index);
  delete[]p;
  len--;
}

template<typename TData>
void CArray<TData>::clear()
{
  len = 0;
  if (data)
    delete[]data;
  data = nullptr;
}

template<typename TData>
unsigned int CArray<TData>::size() const
{
  return len;
}

template<typename TData>
TData& CArray<TData>::operator[](
    unsigned int _index
  )
{
  return data[_index];
}

template<typename TData>
const TData& CArray<TData>::operator[](
    unsigned int _index
  ) const
{
  return data[_index];
}

template<typename TData>
CArray<TData> &CArray<TData>::operator=(
	  CArray<TData> _val
	)
{
  if (this == &_val)
    return *this;
  len = _val.len;
  if (data)
    delete[]data;
  data = new TData[len];
  std::copy(_val.data, _val.data + len, data);
  return *this;
}

template<typename TData>
bool CArray<TData>::operator==(
    const CArray<TData>& _val
  )const
{
  if (len != _val.len)
    return false;
  for (unsigned int i = 0; i < len; ++i)
    if (data[i] != _val.data[i])
      return false;
  return true;
}
template<typename TData>
bool CArray<TData>::operator!=(
    const CArray<TData> &_val
  )const
{
  return !(*this == _val);
}

template<class TData>
void CArray<TData>::printData ()
{
  for (unsigned int i = 0; i < len; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;
}

template<typename TData>
void CArray<TData>::sort(
    TData *_beg, 
    TData* _end
  )
{
  std::sort(_beg, _end);
}


