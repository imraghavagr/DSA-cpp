// https://practice.geeksforgeeks.org/problems/range-minimum-query/1


//given a range, find the maximum value of that range 
//Maximum number of nodes will be 2*n-1 

//Therefor time taken to build the Tree will be O(N)
//TC for query -> O(LogN)

//for node with node number 'n'
//left child -> 2*n + 1
//right child -> 2*n + 2

#include<iostream>
#include<climits>
using namespace std;

//maxsize of array = 1e5 
int arr[100005], seg[4 * 100005]; 

void buildSegTree(int ind, int low, int high){
    if(low == high){
        seg[ind] = arr[low]; 
        return;
    }
    int mid = low + (high -low)/2;
    //post order fashion
    buildSegTree(2*ind+1, low, mid); 
    buildSegTree(2*ind+2, mid+1, high);
    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]); 
}
//Query range -> [l, r]
//current node's range -> [low, high]
//current node's number -> idx
int query(int idx, int low, int high, int l, int r){
    //three cases 
    //1. current node lies completely in query range- return node's data 
    if(low >= l && high <= r){
        return seg[idx];
    }
    //2. does not lies - return INT_MIN
    else if(r < low || l > high)    return INT_MIN;

    //3. overlaps - return max(left, right)
    else{
        int mid = low + (high -low)/2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r); 
        return max(left, right); 
    }
}
// single update - O(logN)
//update arr[i] += val 
void pointUpdate(int idx, int low, int high, int node, int val){
    if(low == high){
        seg[low] += val; 
    }
    else{
        int mid = low + (high -low)/2;
        if(node <= mid && node >= low)  pointUpdate(2*idx+1, low, mid, node, val); 
        else    pointUpdate(2*idx+2, mid+1, high, node, val); 
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }
}
int main()
{   
    int n; 
    cin>>n; 
    //input array 
    for(int i = 0; i<n; i++){
        cin>>arr[i]; 
    }

    //build seg tree () accetps index of root, low, high range 
    buildSegTree(0, 0, n-1);

    int q; 
    cin>>q; 
    while(q--){
        int l, r; 
        cin>>l>>r; 
        cout<<query(0, 0, n-1, l, r)<<endl;
    }
    return 0;
}