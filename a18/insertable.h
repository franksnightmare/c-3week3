#ifndef INSERTABLE_H
#define INSERTABLE_H

#include <memory>
#include <algorithm>
#include <iterator>
#include <deque>
#include <vector>

enum Containers
{
	Vector,
	Deque
};

template <typename DataType, Containers ...container>
class ContainerBase;

template <typename DataType, Containers ...container>
struct ContainerBase<DataType, Vector, container...> : public std::vector<DataType>
{
	public:
		ContainerBase(std::vector<DataType> vec)
		{
			copy(vec.begin(), vec.end(), *this);
		};
		ContainerBase(DataType val)
		{
			this->push_back(val);
		};
		ContainerBase(ContainerBase const &other)
		{
			copy(other.begin(), other.end(), *this);
		};
};

template <typename DataType, Containers container>
std::ostream &operator<<(std::ostream &out, ContainerBase<DataType, container> &obj)
{
	return out;
}

template <typename DataType, Containers ...container>
struct ContainerBase<DataType, Deque, container...> : public std::deque<DataType>
{
	public:
		ContainerBase(std::deque<DataType> deq)
		{
			copy(deq.begin(), deq.end(), *this);
		};
		ContainerBase(DataType val)
		{
			this->push_back(val);
		};
		ContainerBase(ContainerBase const &other)
		{
			copy(other.begin(), other.end(), *this);
		};
};

template <typename DataType, Containers container>
struct Insertable : public ContainerBase<DataType, container>
{
	Insertable(){};
	Insertable(DataType val)
	{
		this->push_back(val);
	};
	Insertable(Insertable const &other)
	{
		copy(other.begin(), other.end(), *this);
	};
	Insertable(Insertable &&tmp){};
};

#endif
