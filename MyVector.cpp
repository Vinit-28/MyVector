#include<iostream>


using namespace std;


template<class datatype>
class MyVector
{
   
    private:
        // Declaration of Private Data Members //
        int len=1,total_elements=0,index=-1;
        datatype *vector;

        // Declaration of Private Member Functions //
        void resize_vector(datatype *vec_pointer);
        bool contains_a_vector();
        char get_datatype();


        
    
    public:
        // Declaration of Public Member Functions //
        void push_in(datatype data);
        void pop_out();
        void flush_vector();
        void sort(bool reverse=false);
        int get_length();
        void show_all();
        bool is_element_exits(datatype data);
        datatype get_element(int ele_index);
        datatype get_sum();
        datatype& operator[](int pos);
        MyVector<datatype> operator+(MyVector vec_obj);
        int implement_binary_search(datatype element_to_search);
        datatype get_product();
};


// --------------- Function Definitions --------------- //



// Function to give a little bit detail about the object of the class "MyVector" //
template<class datatype>
ostream &operator<<(ostream &cout_obj, MyVector<datatype> &obj)
{
    return( cout_obj << "< ClassObject \"MyVector\" >" << endl );
}



// Function to multiply two matrices and return the resultant matrix //
template<class datatype>
MyVector<MyVector<datatype>> matrix_multiplication( MyVector<MyVector<datatype>> Matrix1, MyVector<MyVector<datatype>> Matrix2 )
{

    MyVector<MyVector<datatype>> Resultant_Matrix;

    if( ! ( Matrix1[0].get_datatype() == 'N' && Matrix2[0].get_datatype() == 'N' ) )
    {
        cout << "\nMultiplication is possible only with Numeric Datatypes" << endl;
    }
    else
    {
        if( are_matrices_Compatibility_for_matrix_multiplication(Matrix1,Matrix2) )
        {
            int R1 = Matrix1.get_length(),R2 = Matrix2.get_length(), C1 = Matrix1[0].get_length(),C2 = Matrix2[0].get_length();
            MyVector<datatype> EmptyRow;
            
            for( int i=0; i < R1; i++ )
            {
                Resultant_Matrix.push_in(EmptyRow);
                for( int j=0; j < C2; j++ )
                {
                    Resultant_Matrix[i].push_in(0);
                    for( int k=0; k < C1; k++ )
                    {
                        Resultant_Matrix[i][j] += ( Matrix1[i][k] * Matrix2[k][j] );
                    }
                }
            }
        }
        else
        {
            cout << "\nDimensions are not Compatible for Matrix Multiplication" << endl;
        }
    }
    return Resultant_Matrix;
}




// Function to check whether the muplication between two matrices is possible or not //
template<class datatype>
bool are_matrices_Compatibility_for_matrix_multiplication( MyVector<MyVector<datatype>> Matrix1, MyVector<MyVector<datatype>> Matrix2 )
{
    int R2 = Matrix2.get_length(),C1 = Matrix1[0].get_length(), C2 = Matrix2[0].get_length();
    if( C1 == R2 )
    {
        for(int i=0;i<Matrix1.get_length();i++)
        {
            if( C1 != (Matrix1[i].get_length()) )
                return false;
        }

        for(int i=0;i<R2;i++)
        {
            if( C2 != (Matrix2[i].get_length()) )
                return false;
        }

        return true;
    }
    return false;
}



// --------------- End of Function Definitions --------------- //






// --------------- Class "MyVector"'s Methods Definitions --------------- //


// Method to Push data in a Vector //
template<class datatype>
void MyVector<datatype>::push_in(datatype data)
{
    index+=1;
    total_elements+=1;
    datatype *vec_pointer = new datatype[total_elements];
    resize_vector(vec_pointer);
    vector[index]=data;
}


// Method to Resize a Vector ( works in both cases increasing the vector size or decreasing the vector size) //
template<class datatype>
void MyVector<datatype>::resize_vector(datatype *vec_pointer)
{
    for(int i=0;i<(get_length()-1);i++)
    {
        vec_pointer[i] = vector[i];
    }
    vector = vec_pointer;
}


// Method to Check Whether a Vector Contains a Vector or not //
template<class datatype>
bool MyVector<datatype>::contains_a_vector()
{ 
    if(get_datatype()=='V')
    {
        return true;
    }
    return false;
}



// Method to Pop data from a Vector //
template<class datatype>
void MyVector<datatype>::pop_out()
{
    if(get_length()==0)
    {
        cout << "\nVector is Empty" << endl;
    }
    else
    {
        total_elements-=1;
        datatype *vec_pointer = new datatype[total_elements];
        resize_vector(vec_pointer);
    }
}



// Method to flush/delete all the elements from  a Vector //
template<class datatype>
void MyVector<datatype>::flush_vector()
{
    index=-1;
    total_elements=0;
    datatype *vec_pointer = new datatype[total_elements];
    resize_vector(vec_pointer);
}



// Method to get an element of a particular index from a Vector //
template<class datatype>
datatype MyVector<datatype>::get_element(int ele_index)
{
    if(ele_index>=get_length())
    {
        datatype NO_ELEMENT;
        cout << "\nNo Element Availabe at Index :: " << ele_index << endl;
        return NO_ELEMENT;
    }   
    else
    {
        return vector[ele_index];
    }
}


// Method to get the Length of the Vector //
template<class datatype>
int MyVector<datatype>::get_length()
{
    return total_elements;
}



// Method to Sort the vector ( By-default it will sort the vector in Ascending order but a user can sort the vector in Descending order by passing value of parameter reverse true ) //
template<class datatype>
void MyVector<datatype>::sort(bool reverse)
{
    if(get_length()==0)
    {
        cout << "\nVector is Empty" << endl;
    }
    else
    {
        datatype temp;
        for(int i=0;i<get_length();i++)
        {
            for(int j=i+1;j<get_length();j++)
            {
                if( (reverse==true && vector[i]<vector[j])  || (reverse==false && vector[i]>vector[j]) )
                {
                    temp=vector[i];
                    vector[i]=vector[j];
                    vector[j]=temp;
                }
            }
        }
    }

}



// Method to Show all Elements of a Vector //
template<class datatype>
void MyVector<datatype>::show_all()
{
    if(get_length()==0)
    {
        cout << "\nVector is Empyt" << endl;
    }
    else
    {
        for(int i=0;i<get_length();i++)
        {
            cout << "\nVector [ " << i << " ] Element :: " << vector[i];
        }
    }
}



// Method to check whether an element exists in a vector or not //
template<class datatype>
bool MyVector<datatype>::is_element_exits(datatype data)
{
    if(get_length()==0)
    {
        cout << "\nVector is Empty" << endl;
    }
    else
    {
        for(int i=0;i<get_length();i++)
        {
            if(data == vector[i])
            {
                return true;
            }
        }
    }
    return false;
}



// Method to Overload the Subscript Operator ( [] ) //
template<class datatype>
datatype& MyVector<datatype>::operator[](int pos)
{
    if(pos>=get_length())
    {
        cout << "\nIndex out of bound" << endl;
        exit(0);
    }
    else
    {
        return vector[pos];
    }
}



// Method to get the sum of the vector //
template<class datatype>
datatype MyVector<datatype>:: get_sum()
{
    datatype sum='\0';
    for(int i=0;i<get_length();i++)
    {
        sum = sum+vector[i];
    }
    return sum;
}



// Method to get the type of the vector //
template<class datatype>
char MyVector<datatype>:: get_datatype()
{
    string vec_type = typeid(vector).name();
    if( vec_type=="Pc" )
        return 'C';
    else
    {
        long int len = vec_type.length(), str_index = vec_type.find("string"), MyVector_index = vec_type.find("MyVector");
        if( str_index >= 0 && str_index < len )
            return 'S';
        if( MyVector_index >= 0 && MyVector_index < len)
            return 'V';
    }
    return 'N';
}



// Method to Overload the '+' Operator Which will help to add two vectors //
template<class datatype>
MyVector<datatype> MyVector<datatype>:: operator+(MyVector vec_obj)
{
    MyVector<datatype> temp;

    for(int i=0;i<get_length();i++)
    {
        temp.push_in(vector[i]);
    }

    for(int i=0;i<vec_obj.get_length();i++)
    {
        temp.push_in(vec_obj[i]);
    }
    return temp;
}


// Method to implement binary search on the vector //
template<class datatype>
int MyVector<datatype>:: implement_binary_search(datatype element_to_search)
{
    if(get_length()==0)
    {
        cout << "\nVector is Empty" << endl;
    }
    else
    {
        sort(true);
        int lower=0,upper=(get_length()-1),middle = ((lower+upper)/2);
        while(upper>=lower)
        {
            if( vector[middle] == element_to_search )
            {
                return middle;
            }
            else if( vector[middle] < element_to_search )
            {
                lower = middle + 1;
            }
            else
            {
                upper = middle - 1;
            }
            middle = ((lower+upper)/2);
        }
    }
    return -1;
}



// Method to find the product of the vector //
template<class datatype>
datatype MyVector<datatype>:: get_product()
{
    datatype product=1;
    for(int i=0;i<get_length();i++)
        product*=vector[i];
    return product;
}



// --------------- End of Class "MyVector"'s Methods Definitions --------------- //
