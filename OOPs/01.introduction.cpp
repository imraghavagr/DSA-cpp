/*
Object Oriented Programming refers to the programming that uses the concept of classes and objects 
that helps us implement real-world entities such as polymorphism, inheritance, 
encapsulation, abstraction, etc. 
Some popular OOP languages are c++, java, python, php, c# etc 
*/
#include<iostream>
#include<string>
using namespace std;
class Hero{
    //health is declared private 
    int health;
  public:
    int level;

    void setHealth(int h){
        health = h;
    }
    int getHealth(){
        return health;
    }  
};
int main()
{   
    //statically intantiating an object - h1 of Hero class
    Hero h1;

    //objects can access member functions and member variables using dot (.) operator 

    //the below line will not work... since health is a private member variable, we can not access it outside the class 
    // h1.health = 10;a
    //therefore we will need to use setters for it 
    h1.setHealth(10);

    //but we can access level outside the class directly as it is a public member 
    h1.level = 5;

    cout<<"Level of H1 "<<h1.level<<endl;
    cout<<"Health of H1 "<<h1.getHealth()<<endl;

    //Dynamically instantiating an object h2 of Hero Class 
    Hero *h2 = new Hero;
    //h2 is a pointer of Hero type.. so it will store the address of the memory where h2 is placed.. to access it we will need to use...
    //dereference operator also 

    (*h2).level = 20;
    (*h2).setHealth(100);


    

    cout<<"Level of H2 "<<(*h2).level<<endl;
    cout<<"Health of H2 "<<(*h2).getHealth()<<endl;
    //there is one more way to do it - we can use the '->' operator which gives the value at any address 
    cout<<"Level of H2 "<<h2->level<<endl;
    cout<<"Health of H2 "<<h2->getHealth()<<endl;

    
    return 0;
}