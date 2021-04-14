#include "MyVector.h"

using namespace std;


// Testing of MyVector //
int main()
{

    // Created an instance of class MyVector //
    MyVector<string> vec;

    // Adding elements in the vector //
    vec.push_in("Vinit Tekwani");
    vec.push_in("Sandeep Jadam");
    vec.push_in("Yashwant Sahu");
    vec.push_in("Aman Khushalani");
    vec.push_in("Kunal Verma");

    // Sorting the vector data elements //
    vec.sort(true);

    // Creating Iterator object using MyIterator Class
    MyVector<string> :: MyIterator iter(vec);

    // Iterating through the Vector
    for( iter ; iter != vec.get_end() ; iter += 1)
        cout<<*iter<<endl;

    return 0;
}