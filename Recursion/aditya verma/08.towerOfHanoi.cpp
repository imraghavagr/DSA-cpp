#include<iostream>
using namespace std;
void solve(int n, int source, int destination, int helper, long long &count){
    count++;
    //base case
    if(n == 1){
        cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;
        return;
    }
    
    //hypothesis - solve for smaller input 
    solve(n-1, source, helper, destination, count);
    
    //induction step
    cout<<"move disk "<<n<<" from rod "<<source<<" to rod "<<destination<<endl;
    //move the remaining discs from helper to destination 
    solve(n-1, helper, destination, source, count);
}

// avoid space at the starting of the string in "move disk....."
long long toh(int N, int from, int to, int aux) {
    // Your code here
    long long cnt = 0;
    solve(N,from,to,aux,cnt);
    return cnt;
}
int main()
{   
    int n; //no. of disks
    cin>>n;
    int from = 1;
    int to = 3; 
    int aux = 2;
    cout<<toh(n,from,to,aux)<<endl;
    return 0;
}