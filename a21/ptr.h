#ifndef PTR_H
#define PTR_H

#include <iostream>
#include <typeinfo>

template <typename T>
struct Deleter
{
	T *d_ptr;
	
	Deleter(T *ptr)
	:
	d_ptr(ptr)
	{}
};

template <typename Base>
class Ptr
{
	Base *d_ptr;
	
	public:
		template <typename Derived>
		Ptr(Derived *ptr)
		:
			d_ptr(ptr)
		{
			Deleter<Derived> del(ptr);
		}
		~Ptr()
		{
			delete d_ptr;
		}
		
		void reset(Base *basePtr)
		{
			//delete static_cast<Base *>(d_ptr);
			delete d_ptr;
			d_ptr = basePtr;
		}
};

#endif
