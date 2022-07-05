#include<iostream>
#include<vector>
using namespace std;

//single class for min and max heap
//we can also make two different classes- for min and max heap separately
class Heap{
    vector<int> v;
    bool minHeap; // true means heap type = MIN and minHeap = false means type = max
    bool compare(int a, int b){
        if(minHeap){
            //MIN_HEAP- parent is smaller than cild
            return a<b;
        }
        else{
            //MAX HEAP= parent is greater than child
            return a>b;
        }
    }
    void heapify(int idx){//we will get the idx of the node which we want to heapify
        int leftChildIdx = 2*idx;
        int rightChildIdx = 2*idx + 1;
        //check if the left child and right child exists- lef and right must be <= v.size()-1;
        int correct_idx = idx;
        if(leftChildIdx <= v.size()-1 && compare(v[leftChildIdx],v[idx])){
            correct_idx = leftChildIdx;
        }
        if(rightChildIdx <= v.size()-1 && compare(v[rightChildIdx],v[idx])){
            correct_idx = rightChildIdx;
        }
        if(correct_idx!=idx){ // this condition will also act as a base case in this rec function
            swap(v[idx],v[correct_idx]);
            heapify(correct_idx);
        }
        
    }

public:
    Heap(int default_size = 10, bool type = true){
        v.reserve(default_size);// vector will not expand its size untill the v.size() reaches default size
        v.push_back(-1);//block the 0th index
        minHeap = type;//true or false
    }
    void push(int d){
        v.push_back(d);
        //take d to its correct position 
        //compare with its parent- parent index = child_idx/2
        int idx = v.size()-1;
        int parent = idx/2;

        //keep pushing to the top till either we reach root node or we stop mid way
        //..when curr element is greater than(in min heap) its parent or
        //..when curr element is smaller than(in max heap) its parent root . => USE COMPARE FUNCTION
        while(idx>1 && compare(v[idx],v[parent])){
            //swap the child and parent
            swap(v[idx],v[parent]);
            //also update the index of current element
            //curr element went to parent index
            idx = parent;
            parent = idx/2;
        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        //step 1- swap v[1] with v[last]
        //step 2- Remove the last element 
        //setp 3- Heapify untill the Heap order property is restores

        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    bool empty(){
        return v.size()==1;
    }

};
int main()
{   //give some initial heap size, if that size gets full it will expand as we will use vectors for implementation
    // also we ne need to input the type of the heap
    Heap h;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int no;
        cin >> no;
        h.push(no);
    }
    //remove all the elements 
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    return 0;
}