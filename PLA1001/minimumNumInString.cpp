#include<iostream>
#include<string>
#include<math.h>
#include<climits>
using namespace std;

int solve2(string s){
    int ans = INT_MAX;
    for(int i = s.length()-1; i>=0; i--){
        if(!isalpha(s[i])){
            //now form the number 
            int mf = 1;
            int num = 0;
            while(!isalpha(s[i]) && i>=0){
                num += ((s[i]-'0')*mf);   
                mf *= 10;
                i--;
            }

            //now compare this number with the other numbers
            ans = min(ans,num);
            i+=1;
        }
    }
    return ans;
}
// 123pro4gra90m
int solve1(string s){
    int ans = INT_MAX;
    for(int i = 0; i<s.length(); i++){
        if(!isalpha(s[i])){
            int len = 0;
            while(!isalpha(s[i]) && i<s.length()){
                len++;
                i++;
            }
            i = i -len;
            //now form the number 
            int mf = pow(10,len-1);
            int num = 0;

            while(!isalpha(s[i]) && i<s.length()){
                num += ((s[i]-'0')*mf);   
                mf /= 10;
                i++;
            }

            //now compare this number with the other numbers
            ans = min(ans,num);
            i-=1;
        }
    }
    return ans;
}
int main()
{   
    string s;
    
    cin>>s; //12pro4gra90m    
    cout<<solve1(s)<<endl;
    cout<<solve2(s)<<endl;

    return 0;
}

