#include<iostream>
#include<string>
using namespace std;
class Hero{
    //health is declared private 
    int health;
    int level;

  public:
    
    //constructor does not have any return type, not even void 
    Hero(){
        //default constructor 
        cout<<"Default C'tor called"<<endl;
        health = 0;
        level = 0;
    }

    //parameterized constructor 
    //'this' stores the address of the current object 
    Hero(int health, int level){
        cout<<"parameterised c'tor called"<<endl;
        // health = health;
        // level = level;
        //we can write in any of the two following ways 
        (*this).health = health;
        this->level = level;
    }  
    //this will also work if we do not want to use this keyword 
    // Hero(int h, int l){
    //     health = h;
    //     level = h;
    // }
    
    //another parameterised c'tor with different number of paramters 
    Hero(int health){
        cout<<"parameterised c'tor 2 called"<<endl;
        this->health = health;
    }
    //setter
    void setHealth(int h){
        health = h;
    }
    //getter
    int getHealth(){
        return health;
    }
    void setLevel(int h){
        health = h;
    }
    int getLevel(){
        return health;
    }    
};
int main()
{   
    //statically intantiating an object - h1 of Hero class
    //whenever we instantiate an obect, the constructor will be called automatically 
    Hero h1;
    cout<<"health = "<<h1.getHealth()<<endl;
    cout<<"level = "<<h1.getLevel()<<endl;

    Hero h2(10,10);    

    //still h2.health has garbage value.. because( we wrote health = health in the parameterized c'tor.
    //it assigned value at health parameter that we passed to the health param itself .. 
    //it will not assign the value at health paramter to the data member health of the h2 object
    // cout<<h2.getHealth()<<endl;

    //for it to work properly, we either use different param name than the data member present 
    //or we use "this" keyword if we want to use same names 
    cout<<"health = "<<h2.getHealth()<<endl;
    cout<<"level = "<<h2.getLevel()<<endl;

    Hero h3(15);
    cout<<"health = "<<h3.getHealth()<<endl;
    cout<<"level = "<<h3.getLevel()<<endl;

    return 0;
}