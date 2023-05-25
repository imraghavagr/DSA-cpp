#include<iostream>
using namespace std;
class Hero{
    //health is declared private 
    int health;
    int level;
  public:    
    Hero(){
        cout<<"Simple c'tor called."<<endl;
        health = 10;
        level = 5;
    }
    ~Hero(){
        cout<<"Destructor bhai called "<<endl;
    }
    void setHealth(int h){
        health = h;
    }
    void setLevel(int l){
        level = l;
    }    
    void print(){
        cout<<"Health = "<<health<<" "<<" Level = "<<level<<endl;
    }
};
int main()
{
    //whenever we create a class ... destructor is also creating by itself.. but we can also create our destructors 
    //static 
    Hero a;
    //dynamic 
    Hero * b = new Hero;
    //now a and b are about to go out of scope, that's when the desturctor will be called 

    //now the destructor will be called ... and it will free the memory allocated to the object a 
    //but here, destructor is getting called only for a .. not for b, why? 
    
    //because, jo bhi ojects statically create hote hai unke liye destructor automatically call hota hai .. we do not need to call them 
    //but jo bhi objects dynamically create hote hai unke liye destructor ko call hame manually karna padta hai 
    
    delete b;
    
    return 0;
}