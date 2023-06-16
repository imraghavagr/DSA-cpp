#include<iostream>
using namespace std;
//we need to find the smallest element greater than the target 
//we can modify the ceil and do the same .. or we can directly use the upper_bound() from c++ stl 
//we need to basically find the upper_bound 
char nextGreatestLetter(vector<char>& letters, char target) {
    if(target >= letters.back()) return letters.front();
    int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
    return letters[idx];
}
int main()
{
    return 0;
}