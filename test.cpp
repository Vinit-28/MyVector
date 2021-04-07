#include "MyVector.cpp"

using namespace std;

int main()
{
    
    MyVector<string> vector;

    vector.push_in("Vinit Tekwani");
    vector.push_in("Sandeep Jadam");
    vector.push_in("Yashwant Sahu");
    vector.push_in("Aman Khushalani");
    vector.push_in("Kunal Verma");

    vector.show_all();

    cout<<vector;

    return 0;
}