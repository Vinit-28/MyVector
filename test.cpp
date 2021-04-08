#include "MyVector.cpp"

using namespace std;

int main()
{

    MyVector<int> f;

    f.push_in(10);
    f.push_in(15);
    f.push_in(18);
    f.push_in(16);

    cout<<f.get_sum()<<endl;

    return 0;
}