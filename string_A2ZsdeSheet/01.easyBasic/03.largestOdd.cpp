#include<iostream>
using namespace std;
bool isOdd(char ch){
    return (ch - '0')&1; 
}
string largestOddNumber(string num) {
    //just find the first odd character from right to left 
    int i = num.size()-1; 
    while(i>=0){
        if(isOdd(num[i])){
            //take the entire string from index 0 to index i 
            return num.substr(0, i+1); 
        }
        i--;
    }
    return "";
}
int main()
{
    return 0;
}