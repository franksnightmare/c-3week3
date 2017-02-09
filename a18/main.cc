#include "main.ih"

int main()
{
	deque<string> ds = {"kilo", "lima", "mike"};

    vector<int> vi {1, 2, 3, 4, 5};

    Insertable<int, Vector> iv;
    Insertable<int, Vector> iv2(vi);
    Insertable<int, Vector> iv3(4);
    Insertable<int, Vector> iv4(iv2);

    cout << iv2 << '\n' <<
            iv3 << '\n' <<
            iv4 << '\n';

    iv3.push_back(123);
    cout << iv3 << '\n';

    Insertable<string, Deque> sd(ds);
    sd.push_back("november");

    cout << "sd has " << sd.size() << " elements and contains:\n"
            << sd << '\n';
}
