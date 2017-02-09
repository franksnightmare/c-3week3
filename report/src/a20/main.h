#ifndef MAIN_H
#define MAIN_H

#include <iostream>

enum Operators
    {
	LSH
    };

template <class Derived>
struct Shl
{
    Derived &operator<<=(Derived const &rhs)
    {
	static_cast<Derived &>(*this).shlWrap(rhs);
	return static_cast<Derived &>(*this);
    }
};

template <class Derived, Operators ...ops>
    class SBhandler
{
};

template <class Derived, Operators ...ops>
    class SBhandler<Derived, LSH, ops...>:
        public Shl<Derived>,
        SBhandler<Derived, ops...>
{
};

template <class Derived>
    class SBhandler<Derived>
{
};


template <class Derived, Operators ...ops>
    class ShiftBase:
        public SBhandler<Derived, ops...>
{
    friend Shl<Derived>;

    void shlWrap(Derived const &rhs);
    std::ostream &insertWrap(std::ostream &out) const;

};

template <class Derived, Operators ...ops>
    void ShiftBase<Derived, ops...>::shlWrap(
        Derived const &rhs)
{
    static_cast<Derived &>(static_cast<Shl<Derived>
        &>(*this)).lshift(rhs);
}

class ShlInserter: public ShiftBase<ShlInserter, LSH>
{
    friend class ShiftBase<ShlInserter, LSH>;
    int d_data;

 public:
    ShlInserter(int data);
    ShlInserter(ShlInserter &lhs);
    void swap(ShlInserter &other);
    int Data();

 private:
    void lshift(ShlInserter const &lhs);
};

ShlInserter::ShlInserter(int data)
:
d_data(data)
{}

int ShlInserter::Data()
{
    return d_data;
}
void ShlInserter::lshift(ShlInserter const &lhs)
{
    d_data <<= lhs.d_data;
    std::cout << "lshift called\n";
}

#endif
