/*
Input format- 
5 6 - n-no. of nodes and m - no. of edges
2 1 - signifies that there is a an edge between node 2 and 1 .. also vice-versa (in case of undirected graph)
1 3
2 4
3 4
3 5
4 5
*/
/*
This input format gives the entire information about the graph
Then we can store it in either of two formats :
    a. Adjacency matrix representation
    b. Adjacency list representation - array of vectors or vector of vectors or array of lists. 
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{   
    int n,m;
    cin>>n>>m;
    //for 1 based graph
    vector<vector<int>> adjMat(n+1,vector<int>(n+1,0));
    //if adjMat[i][j] == 1, means there is an edge between i and j
    //                == 0, means there is an edge between j and i
    
    //adjacency list representation
    vector<int> adjList[n+1];

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        //put weight value instead of 1 in case of weighted graph
        adjMat[u][v] = 1; //u --> v
        adjMat[v][u] = 1; //v --> u; remove this in case of directed graph

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout<<"Matrix representation:"<<endl;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }    
    cout<<"Adjacency List represenetation"<<endl;
    for(int i = 0; i<=n; i++){
        cout<<i<<" -> ";
        for(int x : adjList[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}