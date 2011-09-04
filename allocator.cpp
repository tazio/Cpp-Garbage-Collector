
#include "library/dummy_allocator.hpp"

#include <vector>
#include <iostream>

using namespace std;
using namespace gc;

class node
{
public:
    node(int value):m_value(value){};

private:
    int m_value;
};

int main()
{
    cout << "starting" << endl;

    vector<int, dummy_allocator<int> > vect(10);

    vect[0] = 100;
    vect[9] = 100;

    return(0);
}
