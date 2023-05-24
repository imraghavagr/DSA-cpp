#include<iostream>
using namespace std;
class Hero{
    int health, level;
    public:
    Hero(){
        health = 0;
        level = 0;
    }
    Hero(int h, int l){
        health = h;
        level = l;
    }
    void printHero(){
        cout<<health<<" "<<level<<endl;
    }
};
class Student{
    public:
    int sid;
    string sname;
    Student(int id, string name){
        sid = id;
        sname = name;
    }
    //we need to pass temp as call by reference 
    //because if it would be call by value... than lets say we passed s1 from main function .. then its value will be copied 
    //into another object called temp.. and that copying thing will again call the copy c'tor .. and so on .. this 
    //..will result in inf loop 
    Student(Student &temp){
        this->sid = temp.sid;
        this->sname = temp.sname;
    }
    void printStudent(){
        cout<<sid<<" "<<sname<<endl;
    }
};
int main()
{   
    Hero Ramesh(10,10);
    Ramesh.printHero();
    //write now we have not defined our own copy c'tor in the Hero Class.. so default copy constructor will be called 
    Hero Suresh(Ramesh);
    //the above line is equivalent to 
    //Suresh.health = Ramesh.health
    //Suresh.level = Ramesh.level
    Suresh.printHero();


    //But class Student has its own copy c'tor .. so the default copy c'tor will never be called .. the copy c'tor we defined will always be
    //called 
    Student s1(1, "Raghav");
    s1.printStudent();
    Student s2(s1);
    s2.printStudent();
    return 0;
}