#include<iostream>
using namespace std;
class Human{

    public:
        int height;    
        int weight;    
        int age;
        int getAge(){
            return age;
        }
        void setWeight(int w){
            weight = w;
        }
};
//Male class is inheriting Human class publically 
class Male : public Human{
    public:
        string hairColor;
        void sleep(){
            cout<<"Male Sleeping"<<endl;
        }
};
int main()
{   
    Male obj1; //obj1 inherited all the properties of Human class
    cout<<obj1.height<<endl;
    cout<<obj1.weight<<endl;
    cout<<obj1.age<<endl;
    cout<<obj1.hairColor<<endl;
    obj1.sleep();
     
    obj1.setWeight(85);
    cout<<obj1.weight<<endl;
    return 0;
}