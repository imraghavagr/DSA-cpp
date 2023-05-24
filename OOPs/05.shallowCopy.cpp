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

    //lets make a copy of h2 .. here default copy c'tor will be called .. means shallow copy will be made 
    Hero h2(h1);
    h2.print();

    //now lets change the name of h1 
    h1.name[0] = 'G';

    //we have only changed the name of hero h1, then, why did h2.name changed? ->> because of shallow copy .. 
    //same address is shared by both the objects 
    h1.print();
    h2.print();
    return 0;
}