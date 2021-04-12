#include "MyVector.h"

using namespace std;


// Testing of MyVector //
int main()
{

    // Created an instance of class MyVector //
    MyVector<string> vec;

    // Adding elements in the vector //
    vec.push_in("Vinit");
    vec.push_in("Sandeep");
    vec.push_in("Yashwant");
    vec.push_in("Aman");
    vec.push_in("Kunal");

    // Sorting the vector data elements //
    vec.sort(true);

    // Displaying the vector data elements //
    vec.show_elements(0,vec.get_length(),1);

    cout<<endl;
    return 0;
}