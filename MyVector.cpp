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
    
    public:
        // Declaration of Public Member Functions //
        void push_in(datatype data);
        void pop_out();
        void sort(bool reverse=false);
        int get_length();
        void show_all();
        bool is_element_exits(datatype data);
        datatype get_element(int ele_index);
        datatype& operator[](int pos);
    
};


// Function to give a little bit detail about the object of the class "MyVector" //
template<class datatype>
ostream &operator<<(ostream &cout_obj, MyVector<datatype> &obj)
{
    return( cout_obj << "\nThis is an Object of Class \"MyVector\"" << endl );

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
    for(int i=0;i<get_length();i++)
    {
        cout << "\nVector [ " << i+1 << " ] Element :: " << vector[i];
    }
    cout << endl;
}



// Method to check whether an element exists ina vector or not //
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


