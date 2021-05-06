#include<iostream>


using namespace std;


// Class MyVector to create Vector Objects //
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
        char compare_two_vectors(MyVector vec_obj1, MyVector vec_obj2);
        datatype find_min_and_max( string operation, int start=-1, int end=-1);


    
    public:

        // Declaration of Public Inner Class "MyIterator" //
        
        class MyIterator
        {
            private:

                datatype *my_iterator, *backup;
            
            public:

                MyIterator(MyVector<datatype>&);
                void restart_iterator();
                void change_vector(MyVector<datatype>&);
                

                void operator=(datatype*);
                bool operator==(datatype*);
                bool operator!=(datatype*);
                void operator++();
                void operator++(int);
                void operator+=(int);
                void operator--();
                void operator--(int);
                void operator-=(int);
                datatype operator*();

        };


        // Declaration of MyVector Class's Constructor //

        MyVector();
        MyVector(datatype data[], int data_size);
        MyVector(string data, int data_size);



        
        // Declaration of Public Member Functions //
       
        void push_in(datatype data);
        void pop_out();
        void flush_vector();
        void show_elements(int starting_index = 0, int ending_index = -1, int steps = 1);
        void sort(bool reverse=false, int starting_index = 0, int ending_index = -1);
        bool is_element_exits(datatype data);
        int get_length();
        int implement_binary_search(datatype element_to_search);


        datatype& operator[](int pos);
        MyVector<datatype> operator+(MyVector vec_obj);
        void operator+=(MyVector &vec_obj);
        bool operator<( MyVector vec_obj);
        bool operator>( MyVector vec_obj);
        bool operator==( MyVector vec_obj);
        bool operator!=( MyVector vec_obj);
        bool operator<=( MyVector vec_obj);
        bool operator>=( MyVector vec_obj);

        
        datatype get_element(int ele_index);
        datatype get_sum(int starting_index = 0, int ending_index = -1, int steps = 1);
        datatype get_product(int starting_index = 0, int ending_index = -1, int steps = 1);
        datatype get_max(int starting_index = -1, int ending_index = -1);
        datatype get_min(int start=-1, int end=-1);
        datatype *get_iterator();
        datatype *get_begin();
        datatype *get_end();


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


// This is a Defualt Constructor //
template<class datatype>
MyVector<datatype> :: MyVector()
{}



// This Constructor Will take an array and will push each of its element up to the given length in the current vector //
template<class datatype>
MyVector<datatype> :: MyVector(datatype data[], int data_size)
{
    for ( int i=0; i<data_size; i++ )
    {
        (*this).push_in(data[i]);
    }
}



// This Constructor will take a string and will Push each of its character up to the given lenght in current vector //
template<class datatype>
MyVector<datatype> :: MyVector(string data, int data_size)
{
    for ( int i=0; i<data_size; i++ )
    {
        (*this).push_in(data[i]);
    }
}



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
        datatype *vec_pointer = new datatype[total_elements-1];
        resize_vector(vec_pointer);
        total_elements-=1;
        index-=1;
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
void MyVector<datatype>::sort(bool reverse, int starting_index, int ending_index)
{
    if(get_length()==0)
    {
        cout << "\nVector is Empty" << endl;
    }
    else
    {
        datatype temp;
        if(ending_index == -1)
            ending_index=get_length();
        for(int i=starting_index;i<ending_index;i++)
        {
            for(int j=i+1;j<ending_index;j++)
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
void MyVector<datatype>::show_elements( int starting_index , int ending_index , int steps )
{
    if(get_length()==0)
    {
        cout << "\nVector is Empyt" << endl;
    }
    else
    {
        if( ending_index == -1)
            ending_index = get_length();

        for(int i=starting_index;i<ending_index;i+= steps)
        {
            if(i<total_elements)
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
datatype MyVector<datatype>:: get_sum(int starting_index, int ending_index, int steps)
{
    datatype sum;
    if(get_length() == 0)
    {
        cout << "Vector is Empty" <<endl;
    }
    else
    {   
        if( ending_index == -1)
            ending_index = get_length();
        sum=vector[starting_index];

        for(int i=starting_index+steps; i<ending_index; i += steps)
            if (i<total_elements)
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



// Method to Overload the '+=' Operator  //
template<class datatype>
void MyVector<datatype>:: operator+=(MyVector &vec_obj)
{
    for(int i=0;i<vec_obj.get_length();i++)
    {
        push_in(vec_obj[i]);
    }
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
        sort();
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
datatype MyVector<datatype>:: get_product(int starting_index , int ending_index , int steps )
{
    datatype product;
    if(get_length()==0)
    {
        cout<< "\nVector is Empty" <<endl;
    }
    else
    {
        if( ending_index == -1)
            ending_index=get_length();

        product = vector[starting_index];
        
        for(int i=starting_index+steps; i<ending_index; i+=steps)
            if ( i<total_elements )
                product*=vector[i];
    }
    return product;
}



// Method to find the product of the vector //
template<class datatype>
datatype MyVector<datatype>:: find_min_and_max( string operation, int starting_index, int ending_index )
{
    datatype value;

    if(get_length()==0)
    {
        cout << "\nVector is Empty" << endl;
    }
    else
    {
        value = vector[starting_index];
        
        if( ending_index == -1)
            ending_index = get_length();
        
        for(int i = starting_index; i < ending_index; i++ )
        {
            if( i < total_elements )
                if ( (operation == "Max" && vector[i] > value) || (operation == "Min" && vector[i] < value) )
                    value = vector[i];
        }
    }
    return value;
}




// Method to find the product of the vector //
template<class datatype>
datatype MyVector<datatype>:: get_max(int starting_index, int ending_index)
{
    datatype max_value = find_min_and_max("Max", starting_index, ending_index);
    return max_value;
}



// Method to find the product of the vector //
template<class datatype>
datatype MyVector<datatype>:: get_min(int starting_index, int ending_index)
{
    datatype min_value = find_min_and_max("Min", starting_index, ending_index);
    return min_value;
}



// Method to compare two vectors  //
template<class datatype>
char MyVector<datatype>:: compare_two_vectors(MyVector vec_obj1, MyVector vec_obj2)
{
    char result;

    if( vec_obj1.get_sum() < vec_obj2.get_sum() )
        result = '<';
    else if( vec_obj1.get_sum() == vec_obj2.get_sum() )
        result = '=';
    else
        result = '>';
    
    return result;
}



// Method to overload the '<' operator //
template<class datatype>
bool MyVector<datatype>:: operator<(MyVector vec_obj)
{
    if ( compare_two_vectors( *this, vec_obj) == '<')
        return true;
    return false;
}



// Method to overload the '>' operator //
template<class datatype>
bool MyVector<datatype>:: operator>(MyVector vec_obj)
{
    if ( compare_two_vectors( *this, vec_obj) == '>')
        return true;
    return false;
}



// Method to overload the '==' operator //
template<class datatype>
bool MyVector<datatype>:: operator==(MyVector vec_obj)
{
    if ( compare_two_vectors( *this, vec_obj) == '=')
        return true;
    return false;
}



// Method to overload the '!=' operator //
template<class datatype>
bool MyVector<datatype>:: operator!=(MyVector vec_obj)
{
    if ( compare_two_vectors( *this, vec_obj) == '=')
        return false;
    return true;
}



// Method to overload the '<=' operator //
template<class datatype>
bool MyVector<datatype>:: operator<=(MyVector vec_obj)
{
    char result = compare_two_vectors( *this, vec_obj);
    if (  result == '<' or result == '=' )
        return true;
    return false;
}



// Method to overload the '>=' operator //
template<class datatype>
bool MyVector<datatype>:: operator>=(MyVector vec_obj)
{
    char result = compare_two_vectors( *this, vec_obj);
    if (  result == '>' or result == '=' )
        return true;
    return false;
}



// Method to get the address of the first element of the vector //
template<class datatype>
datatype *MyVector<datatype>::get_begin()
{
    return (&vector[0]);
}



// Method to get the address of the last element of the vector //
template<class datatype>
datatype *MyVector<datatype>::get_end()
{
    return (&vector[total_elements]);
}



// ---------- Methods Definition of Class "MyIterator" ---------- //



// Constructor of Class "MyIterator" //
template<class datatype>
MyVector<datatype>::MyIterator::MyIterator(MyVector<datatype> &vec_obj)
{
    my_iterator = backup = vec_obj.vector;
}



// Method to restart or reposition the iterator to its first position //
template<class datatype>
void MyVector<datatype>::MyIterator:: restart_iterator()
{
    my_iterator = backup;
}



// Method to change the vector object //
template<class datatype>
void MyVector<datatype>::MyIterator:: change_vector(MyVector<datatype> &vec_obj)
{
    my_iterator = backup = vec_obj.vector;
}



// Method to Overload the "=" Operator //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator=(datatype *p)
{
    my_iterator = p;
}



// Method to Overload the "==" Operator //
template<class datatype>
bool MyVector<datatype>::MyIterator:: operator==(datatype *pointer_object)
{
    if(pointer_object == my_iterator)
        return true;
    return false;
}



// Method to Overload the "!=" Operator //
template<class datatype>
bool MyVector<datatype>::MyIterator:: operator!=(datatype *pointer_object)
{
    if(pointer_object == my_iterator)
        return false;
    return true;
}



// Method to Overload the "++" Operator ( Pre - Increment ) //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator++()
{
    my_iterator++;
}



// Method to Overload the "++" Operator ( Post - Increment ) //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator++(int)
{
    my_iterator++;
}



// Method to Overload the "--" Operator ( Pre - Decrement ) //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator--()
{
    my_iterator--;
}



// Method to Overload the "--" Operator ( Post - Decrement ) //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator--(int)
{
    my_iterator--;
}



// Method to Overload the "*" Operator //
template<class datatype>
datatype MyVector<datatype>::MyIterator:: operator*()
{
    return *my_iterator;
}



// Method to Overload the "+=" Operator //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator+=(int Increment)
{
    my_iterator+=Increment;
}



// Method to Overload the "-=" Operator //
template<class datatype>
void MyVector<datatype>::MyIterator:: operator-=(int Decrement)
{
    my_iterator-=Decrement;
}



// ---------- END of Methods Definition of Class "MyIterator" ---------- //




// --------------- End of Class "MyVector"'s Methods Definitions --------------- //
