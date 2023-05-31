#include<iostream>
#include<vector>
using namespace std;
int main()
{   

    vector<int> v = {1,2,3,4,5};
    //               0 1 2 3 4
    int n = v.size(); //5 
    
    for(int i = 1; i<n; i++){
        if(v[i] < v[i-1]){
            cout<<"false";
            break;
        }
    }
    return 0;
}
