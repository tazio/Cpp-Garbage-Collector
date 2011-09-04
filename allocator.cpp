
#include "library/dummy_allocator.hpp"

#include <vector>
#include <iostream>

using namespace std;
using namespace gc;

class node
{
public:

private:
    int m_value;
};

int main()
{
    cout << "starting" << endl;

    vector<node, dummy_allocator<node> > vect(10);

    //vect[0] = 100;
    //vect[9] = 100;

    return(0);
}
