#include<iostream>
using namespace std;
static bool compare(string &a, string &b){
    return a.length()<b.length();
}
bool check(string &a, string &b){
    if(a.length() - b.length() != 1)    return false;

    int ptr1 = 0, ptr2 =0; 
    while(ptr1<a.length()){
        if(a[ptr1] == b[ptr2]){
            ptr1++;
            ptr2++;
        }
        else    ptr1++;
    }
    return ptr1 == a.length() && ptr2 == b.length();
}
int longestStrChain(vector<string>& words) {
    //sort by length of words 
    sort(words.begin(), words.end(), compare);
    vector<int> dp(words.size(), 1);
    int maxi = 1;
    for(int i = 0; i<words.size(); i++){
        for(int j = 0; j<i; j++){
            if(check(words[i], words[j])){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int main()
{
    return 0;
}