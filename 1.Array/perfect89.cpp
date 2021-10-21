#include<iostream>
#include<vector>
using namespace std;
vector<string> vec; //stores all perfect 89 string
void calc(string s,int num8,int num9) {
    if(num8==0 && num9==0) {
        vec.push_back(s);
        return;
    }
    if(num8>num9)
        return;
    if(num8<0 || num9<=0)
        return;
    calc(s+'8',num8-1,num9);
    calc(s+'9',num8,num9-1);
}
int main()
{
    calc("",4,4); //Intial string, count of 8, count of 9
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;
}