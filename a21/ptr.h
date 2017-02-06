#ifndef PTR_H
#define PTR_H

#include <iostream>
#include <typeinfo>

//template <typename Base, typename Derived>
//class Ptr;

template <typename Base>
class Ptr
{
	Base *d_ptr;
	
	public:
		Ptr(auto *basePtr)
		:
			d_ptr(basePtr)
		{
			if (typeid(*basePtr) != typeid(Base))
			{
				
				std::cerr << "We got a derived case!\n";
			}
		}
		~Ptr()
		{
			//delete static_cast<Base *>(d_ptr);
			delete d_ptr;
		}
		
		void reset(auto *basePtr)
		{
			//delete static_cast<Base *>(d_ptr);
			d_ptr = basePtr;
		}
};

#endif
