#include<iostream>
using namespace std;
class Hero{
    //health is declared private 
    int health;
    int level;
  public:    
    Hero(){
        health = 10;
        level = 5;
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
    Hero a;
    Hero b; 
    a.setHealth(20);
    a.setLevel(50);
    cout<<"Hero A : ";
    a.print();
    cout<<"Hero B : ";
    b.print();

    //now lets copy the values of a into b also 
    b = a; 
    /*
    the above line is equivalent to following two lines 
    b.health = a.health 
    b.level = a.level
    */
    cout<<"Hero B : ";
    a.print();
    return 0;
}