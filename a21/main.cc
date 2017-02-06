#include <iostream>
#include "ptr.h"

using namespace std;

struct Base
{
	// not a virtual destructor
	~Base()
	{
		cerr << "Base destr.\n";
	}
};

struct Derived: public Base
{
	// no overriding
	~Derived()
	{
		cerr << "Derived's destructor\n";
	}
};

struct Derived2: public Base
{
	// no overriding
	~Derived2()
	{
		cerr << "Derived2's destructor\n";
	}
};

int main()
{
	{
		Ptr<Base> p1(new Derived);
	}
	Ptr<Base> p2(new Derived2);
	p2.reset(new Derived);
}
