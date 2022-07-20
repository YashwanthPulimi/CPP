#include <iostream>
using namespace std;
class polynomial
{
    int *degcoeff;
    int capacity;

public:
    polynomial()
    {
        this->degcoeff = new int[5];
        this->capacity = 5;
    }
    polynomial(int c)
    {
        this->capacity = c;
        this->degcoeff = new int[capacity + 1];
    }
    // copy constructor
    polynomial (polynomial const &p){
        int *newdeg=new int[p.capacity+1];
            
        for(int i=0;i<=p.capacity;i++)
            newdeg[i]=p.degcoeff[i];
            
        this->degcoeff=newdeg;
        
        this->capacity=p.capacity;
    }

    void setcoefficent(int d, int c)
    {
        if (d == capacity)
        {
            int *newdeg = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdeg[i] = degcoeff[i];
            }
            delete[] degcoeff;
            degcoeff = newdeg;
            capacity *= 2;
        }
        degcoeff[d] = c;
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    polynomial operator+(polynomial const &p)
    {
        int cap = max(this->capacity, p.capacity);
        polynomial p3(cap);
        for (int i = 0; i < cap; i++)
        {
            p3.degcoeff[i] = this->degcoeff[i] + p.degcoeff[i];
        }
        return p3;
    }
     polynomial operator-(polynomial const &p)
    {
        int cap = max(this->capacity, p.capacity);
        polynomial p3(cap);
        for (int i = 0; i < cap; i++)
        {
            p3.degcoeff[i] = this->degcoeff[i] - p.degcoeff[i];
        }
        return p3;
    }
    polynomial operator*(polynomial const &p)
    {
        int cap = max(this->capacity, p.capacity);
        polynomial p3(cap);
        for (int i = 0; i < this->capacity; i++)
        {
            for(int j=0;j<p.capacity;j++){
                p3.degcoeff[i+j]+=this->degcoeff[i]*p.degcoeff[j];
            }
        }
        return p3;
    }
     void operator=(polynomial const &p){
        int *newdeg=new int[p.capacity+1];
        //Copy the contents
        for(int i=0;i<p.capacity;i++)
            newdeg[i]=p.degcoeff[i];
            
        
        this->degcoeff=newdeg;
        
        this->capacity=p.capacity;
    }

    void print(){

    for(int i=0;i<capacity;i++){
        if(degcoeff[i]!=0){
        cout<<degcoeff[i]<<"x"<<i<<" ";
    }}
    cout<<endl;
}
};
int main()
{

    int count1,count2,choice;
    cin >> count1;

     int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    polynomial first;
    for(int i = 0; i < count1; i++){
        first.setcoefficent(degree1[i],coeff1[i]);
    }
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    polynomial second;
    for(int i = 0; i < count2; i++){
        second.setcoefficent(degree2[i],coeff2[i]);
    }
    cin >> choice;
    
    polynomial result;

    switch (choice){
        // add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            polynomial third(first);
            if(third.degcoeff == first.degcoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
        case 5 : // Copy assignment operator
        {
            polynomial fourth(first);
            if(fourth.degcoeff == first.degcoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }
    

}