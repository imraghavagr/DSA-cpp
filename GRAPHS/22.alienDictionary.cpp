//https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
#include<iostream>
using namespace std;
void topologicalSort(vector<int> adj[], int V, vector<int> &ans){
    //Kahn's algo
    vector<int> indegree(V, 0);
    for(int i = 0; i<V; i++)
        for(int j : adj[i])
            indegree[j]++;
    
    //push all the nodes with indegree 0 into the queue
    queue<int> q;
    for(int i = 0; i<V; i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int x : adj[node]){
            indegree[x]--;
            if(indegree[x] == 0)    q.push(x);
        }
    }
}
string findOrder(string dict[], int N, int K) {
    //we have K distinct letters - no of nodes of our directed graph 
    vector<int> adj[K];
    
    for(int i = 0; i<N-1; i++){
        string a = dict[i]; //"baa"    
        string b = dict[i+1]; //"abcd"
        int len = min(a.length(), b.length());
        //go and check till len 
        for(int i = 0; i<len; i++){
            //find the first char that is different
            if(a[i] != b[i]){
                //means a[i] comes before b[i]
                //or we can say that there is an edge from a[i] to b[i]
                adj[a[i] - 'a'].push_back(b[i] - 'a'); // a[i] - 'a' will convert a into 0, b into 1.. 
                break;
            }
        }
    }
    //now once we have our DG ready, lets apply kahns algo (topo sort) on it
    vector<int> ans;
    topologicalSort(adj, K, ans);
    string order;
    for(int i = 0; i<K; i++){
        order.push_back((char)(ans[i] + 'a'));
    }
    return order;
}
    
int main()
{
    return 0;
}