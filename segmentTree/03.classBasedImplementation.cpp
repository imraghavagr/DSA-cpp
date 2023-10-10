#include<iostream>
using namespace std;
class SegmentTree{
public:
    vector<int> seg; 
    SegmentTree(){
        seg.resize(400004); 
    }
    int buildTree(int parentNode = 0, int low = 0, int high = 100001){
        if(low == high){
            return seg[parentNode] = 0; 
        }
        int mid = low + (high-low)/2; 
        int left = buildTree(2*parentNode+1, low, mid);
        int right = buildTree(2*parentNode+2, mid+1, high);

        return seg[parentNode] = max(left, right);
    }
    int query(int l, int r, int node = 0, int low = 0, int high = 100001){
        //1. current node lies in query node range 
        if(low >= l && high <= r)   return seg[node]; 
        //2. does not lies in range of query 
        else if(r < low || l > high)    return INT_MIN; 
        //3. overlapping 
        else{
            int mid = low + (high - low)/2; 
            int left = query(l, r, 2*node+1, low, mid); 
            int right = query(l, r, 2*node+2, mid+1, high); 
            return max(left, right); 
        }
    }
    void pointUpdate(int node, int val, int parentNode = 0, int low = 0, int high = 100001){
        if(low == high) seg[parentNode] = val; 
        else{
            // int mid = low + (high - low)/2; 
            int mid = (low+high)/2; 
            if(node <= mid && node >= low)  
                pointUpdate(node, val, 2*parentNode+1, low, mid); 
            else   
                pointUpdate(node, val, 2*parentNode+2, mid+1, high); 

            seg[parentNode] = max(seg[2*parentNode+1], seg[2*parentNode+2]);
        }
    }
    int maxElement(){
        return seg[0];
    }
};
int main()
{
    return 0;
}