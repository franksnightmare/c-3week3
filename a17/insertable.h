#ifndef INSERTABLE_H
#define INSERTABLE_H

#include <vector>
#include <deque>
#include <memory>

template <typename DataType, 
	template <typename, typename = std::allocator<DataType>> class Container>
struct Insertable : public Container<DataType>
{
	Insertable(){};
	Insertable(Container<DataType> container){};
	Insertable(int val){};
	Insertable(Insertable const &other){};
	Insertable(Insertable &&tmp){};
};
template <typename DataType, 
	template <typename, typename = std::allocator<DataType>> class Container>
std::ostream &operator<<(std::ostream &out, Insertable<DataType, Container> &obj)
{
	return out;
}

#endif
