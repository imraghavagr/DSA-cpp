//https://www.interviewbit.com/problems/nearest-smaller-element/
#include<iostream>
using namespace std;
vector<int> Solution::prevSmaller(vector<int> &v) {
stack<int> s;
vector<int> ans;
for(int i = 0; i<v.size(); i++){
    if(s.empty()){
        ans.push_back(-1);
    }
    else if(!s.empty() and s.top()<v[i]){
        ans.push_back(s.top());
    }
    else if(!s.empty() and s.top()>=v[i]){
        while(s.size()>0 and s.top()>=v[i]){
            s.pop();
        }
        if(s.size()==0){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
    }
    s.push(v[i]);

}
return ans;
}
int main()
{
    return 0;
}