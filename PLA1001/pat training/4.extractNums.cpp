#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{   
    string s;
    getline(cin,s);
    // cout<<s<<endl;
    vector<long long> nums;
    long long ans = -1;
    for(int i = 0; i<s.length(); i++){
        if(isdigit(s[i])){
            long long num = s[i] - '0';
            //find the number 
            i++;
            while(isdigit(s[i])){
                int d = s[i] - '0';
                num *= 10;
                num = num + d;
                i++;
            }
            ans = max(ans, num);
            // nums.push_back(num);
        }
    }
    // for(auto it : nums) cout<<it<<" ";
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}