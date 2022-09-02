#include<iostream>
using namespace std;

//even-odd
bool isEven(int n){
    if(n&1){
        //odd
        return false;
    }
    else{
        return true;
    }
}
int ithBitFromRight(int n, int i){
    //given a number n and an index i, find the ith bit from the right of binary repr of n
    int mask = (1<<i);
    int x = n&mask;
    
    (x>0)? x = 1:x = 0;
    return x;
}
void setIthBit(int&n, int i){
    int mask = (1<<i);
    n = n|mask;
}
void clearIthBit(int &n, int i){
    int mask =  ~(1<<i);
    n = n & mask;
}
void updateIthBitByOneOrZero(int &n, int i, int v){
    //if v = 1, set the ith bit or clear the ith bit if v = 0
    if(v==1){
        setIthBit(n,i);
    }
    else{
        clearIthBit(n,i);
    }
}
void clearLastIthBit(int &n, int i){
    int mask = (-1)<<i;
    n = n&mask;
}
void clearRangeOfBits(int &n, int i, int j){
    int a = (-1)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    n = n&mask;
}
void solve(int &n, int m, int i, int j){
    //from i to j in n, put bits of m
    
    //step 1 - clear bits in n from i to j
    clearRangeOfBits(n,i,j);

    //make the mask
    int mask = m<<i;

    //calculate the result 
    n = n|mask;
}
int main(){
    // int n,i;
    // cin>>n>>i;
    // // cout<<ithBitFromRight(n,i)<<endl;
    // cout<<"Before changing :"<<n<<endl;
    // setIthBit(n,i);
    // cout<<"After setting "<<i<<" th bit :"<<n<<endl;
    // clearIthBit(n,i);
    // cout<<n<<endl;

    // int m = 5;
	// updateIthBitByOneOrZero(m,2,0);
	// cout<<m<<endl;
	// updateIthBitByOneOrZero(m,3,1);
	// cout<<m<<endl;
    // int n = 15;
    // cout<<n<<endl;
    // clearLastIthBit(n,3);
    // cout<<n<<endl;
    // int n = 31;
    // clearRangeOfBits(n,1,3);
    // cout<<n<<endl;
    // cout<<(0<<2)<<endl;
    int n = 5, m = 3;
    int i =1, j = 2;
    solve(n,m,i,j);
    cout<<n<<endl;
    return 0;
}