#include<iostream>
#include<cstring>
using namespace std;

// Read N strings and print the largest string. Each string can have upto 1000 chars
int main(){
    
    int n;
    cin>>n;
    cin.get(); // to consume one '\n' pressed after entering n
    char s[1000];
    
    int len = 0;
    int largestLen = 0;
    char ans[1000];

    while(n--){
        cin.getline(s,1000);
        int len = strlen(s);
        if(len>largestLen){
            largestLen = len;
            strcpy(ans,s);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}