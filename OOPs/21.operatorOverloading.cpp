#include<iostream>
using namespace std;
class Student{
    public:
        int marks;
        Student(int marks){
            this->marks = marks;
        }
        //we are overloading the operator '+', by giving it many forms 
        int operator + (Student &s){
            cout<<"Mai overloading operator hu "<<endl;
            int value1 = this->marks;
            int value2 = s.marks;
            return value1-value2;
        }
};
int main()
{   
    Student s1(100);
    Student s2(90); 
    //we have overloading the '+' operator and changes its functionality 
    cout<<s1+s2<<endl;

    int x = 5;
    int y = 10;
    //operator overloading only workds for usewr defined objects .. this will still do the addition 
    cout<<x+y<<endl;
    return 0;
}