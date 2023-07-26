#include <iostream>
#include <vector_without_iterator.h>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
    vector<int> vec;
    Gvector<int> gvec;

    vec.push_back(111);
    gvec.push_back(222);

    cout << vec[0] << endl;
    cout << gvec[0] << endl;

    cout << vec.capacity() << endl;
    cout << gvec.capacity() << endl;

    vec.push_back(333);
    gvec.push_back(444);

    cout << vec.size() << endl;
    cout << vec.size() << endl;

    vec.at(1) = 5;
    gvec.at(1) = 6;

    cout << vec.at(1) << endl;
    cout << gvec.at(1) << endl;

    vec.pop_back();
    cout << vec.max_size() << endl;
    cout << vec.capacity() << endl;

    vector<int> vec2;
    vec = vec2;
    Gvector<int> gvec2;
    gvec = gvec2;

    cout << vec.size() << endl;
    cout << gvec.size() << endl;

    return 0;
}