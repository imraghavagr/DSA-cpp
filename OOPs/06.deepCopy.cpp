#include<iostream>
#include<cstring>
using namespace std;
class Hero{
    int health;
    public:
    char *name;
    Hero(){
        name = new char[100];
        health = 10;
    }
    //lets make our own copy c'tor to make deep copy (new char array for name)
    Hero(Hero &temp){
        char *arr = new char[strlen(temp.name)+1];
        strcpy(arr, temp.name);
        this->name = arr;
        this->health = temp.health;
    }   
    void setName(char *name){
        strcpy(this->name, name);
    }
    void print(){
        cout<<name<<" "<<health<<endl;
    }
};
int main()
{
    Hero h1;
    char name[] = "Babbar";
    h1.setName(name);
    h1.print();

    //lets make a copy of h2 .. here our custom copy c'tor will be called .. means deep copy will be made 
    Hero h2(h1);
    h2.print();

    //now lets change the name of h1 
    h1.name[0] = 'G';

    //we have only changed the name of hero h1, and the name of h2 remains unchanged 
    //two separate name arrays are formed 
    h1.print();
    h2.print();
    return 0;
}