#include<iostream>
using namespace std;
bool check(int a, int b, int c, int d){
    if(c-a > 0){
        //means ..final position of neimar is right of his current position
        if(b == 1 && (c-a) == d){
            return true;
        }
        else if(b != 1 && (c-a)%b <= d && ((d-(c-a)%b))%2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(b == 1 && (a-c) == d){
            return true;
        }
        else if(b != 1 && (a-c)%b <= d && ((d-(a-c)%b))%2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    int a,b,c,d;
    while(t--){
        cin>>a>>b>>c>>d;
        if(check(a,b,c,d)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}