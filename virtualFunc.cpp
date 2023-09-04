#include<iostream>
using namespace std;
class A{
public:
    int a;
    void hello(){
        cout<<"hello A"<<endl;
    }
    virtual void bye(){
        cout<<"bye A"<<endl;
    }
};
class B : public A{
public:
    virtual void bye(){
        cout<<"bye B"<<endl;
    }
        void hello(){
        cout<<"hello B"<<endl;
    }
};
class C : public A{
public:
    virtual void bye(){
        cout<<"bye C"<<endl;
    }
    void hello(){
        cout<<"hello C"<<endl;
    }
};
int main()
{    
    
    A a; 
    A *p;
    p = &a; 

    p->bye();
     
    B b; 
    C c; 
    p = &b;     
    //function overriding in a dynamic way using virtual functions 
    p->bye();

    p = &c; 
    p->bye();
    

    a.hello();

    b.hello(); 

    c.hello(); 


    p->hello(); 
    return 0;
}