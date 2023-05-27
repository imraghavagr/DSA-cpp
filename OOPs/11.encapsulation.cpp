#include<iostream>
using namespace std;
//making a class is itself encapsulation 
//A class wraps up together the data members and members functions together
class Student{
    private:
        string name;
        int age;
        int height;
    public:
        int getAge(){
            return age;
        }
};
int main()
{   
    Student s;
    cout<<"All well "<<endl;
    return 0;
}