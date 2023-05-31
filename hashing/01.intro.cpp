#include<iostream>
#include<vector>
#include<list>
using namespace std;
class MyHashSet {
    int size;
    vector<list<int>> buckets;
    int findHashCode(int key){
        //our key is already an integer, so it can directly act as index for the buckets 
        //but we can add path compression by doing key%1000.. i.e. we have shortened our
        //size from 1e6 to 1000 
        return key % size;
        //later on we will handle collision using open hashing a.k.a separate chaining
    }
    bool containsKey(int key, list<int>& bucket){
        //now bucket is a list and we need to check if key is present in it or not 
        for(int num : bucket){
            if(num == key)  return true;
        }
        return false;
    }
public:
    MyHashSet() {
        size = 1000;
        buckets = vector<list<int>>(size);
    }
    
    void add(int key) {
        int index = findHashCode(key);
        //now we will add the given key into the hashed index 
        //first lets find out the address of the list stores at 'index' index 
        list<int>&bucket = buckets[index];
        
        //add the key if bucket already does not contains the key 
        if(!containsKey(key, bucket)){
            bucket.push_back(key);
        }
    }
    
    void remove(int key) {
        int index = findHashCode(key);
        list<int>& bucket = buckets[index];
        //remove the key if it is present 
        if(containsKey(key, bucket)){
            bucket.remove(key); //built in method present in list stl
        }
    }
    
    bool contains(int key) {
        int index = findHashCode(key);
        list<int>& bucket = buckets[index];
        return containsKey(key, bucket);
    }
};
int main()
{   
    MyHashSet st;
    st.add(2);//2
    st.add(3);//2 3
    cout<<st.contains(3)<<endl; // true
    st.add(3); // 2 3
    st.remove(3); // 2
    cout<<st.contains(3)<<endl; // false
    cout<<st.contains(2)<<endl; // true
    return 0;
}