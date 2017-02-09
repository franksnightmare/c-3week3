#ifndef PTR_H
#define PTR_H

#include <functional>

template <typename Base>
class Ptr
{
	Base *d_ptr;
	std::function<void(Base*)> d_deleter;
	
	public:
		// Set pointer and deleter
		template <typename Derived>
		Ptr(Derived *ptr)
		:
			d_ptr(ptr),
			d_deleter([](Base *ptr) {delete static_cast<Derived*>(ptr);})
		{}
		
		// Call deleter on destruction
		~Ptr()
		{
			d_deleter(d_ptr);
		}
		
		// Call deleter and set the new pointer and deleter
		template <typename Derived>
		void reset(Derived *basePtr)
		{
			d_deleter(d_ptr);
			
			d_ptr = basePtr;
			d_deleter = [](Base *ptr) {delete static_cast<Derived*>(ptr);};
		}
};

#endif
