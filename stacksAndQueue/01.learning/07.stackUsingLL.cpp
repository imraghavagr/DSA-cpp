#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int> l; 
    public:
    void push(int x){
        l.push_back(x);
    }
    void pop(){
        if(l.size() > 0)
            l.pop_back();
    }
    int top(){
        return l.back();
    }
};
int main()
{   
    
    return 0;
}