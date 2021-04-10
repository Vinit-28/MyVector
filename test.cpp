#include "MyVector.cpp"

using namespace std;



// Trying to Multiply Matrices //
int main()
{

    MyVector<MyVector<int>> Mat1,Mat2, Result;
    MyVector<int> Row;

    Row.push_in(1);
    Row.push_in(2);
    Row.push_in(3);

    Mat1.push_in(Row);
    Mat2.push_in(Row);

    Row.flush_vector();

    Row.push_in(4);
    Row.push_in(5);
    Row.push_in(6);

    Mat1.push_in(Row);
    Mat2.push_in(Row);

    Row.flush_vector();


    Row.push_in(7);
    Row.push_in(8);
    Row.push_in(9);

    Mat1.push_in(Row);
    Mat2.push_in(Row);


    Result = matrix_multiplication(Mat1,Mat2);


    // Printing the Resultant Matrix //
    for(int i=0;i<Result.get_length();i++)
    {
        for(int j=0;j<Result[i].get_length();j++)
            cout << Result[i][j] << "\t";
        cout << endl;
    }


    return 0;
}