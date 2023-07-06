#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> ans(numRows);    
    //iterate from 0 to numRows - 1
    for(int i = 0; i<numRows; i++){
        //for each row, resize the current vector to the size of the required columns in that row
        ans[i].resize(i+1);
        
        ans[i][0] = ans[i][i] = 1;
        
        //now fill up the remaining cols 
        for(int j = 1; j<i; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}
//another approach- using nCr
void generateCurrRow(int rowIdx, vector<int> &temp){
    //total elements in this row will be rowIdx+1;
    temp.push_back(1); //first element will always be 1 
    
    //and we will find the remaining rowIdx number of elements using 
    //optimal ncr way 
    int element = 1; 
    int r = rowIdx;
    for(int i = 1; i<=rowIdx; i++){
        // numerator = numerator * r;
        // denominator = denominator * i;
        //instead of above two we can write following to avoid overflow
        element = element * r; 
        element = element / i;           
        temp.push_back(element);
        r--; 
    }
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i = 0; i<numRows; i++){
        vector<int> temp; 
        generateCurrRow(i,temp);
        ans.push_back(temp);
    }
    return ans; 
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v = generate(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}