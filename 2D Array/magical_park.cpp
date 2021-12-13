//https://hack.codingblocks.com/app/practice/6/1051/problem
#include<iostream>
using namespace std;
int helpPiyush(char arr[100][100], int n, int m, int k, int s){
    /*
    '.' - obstacle - strength decreases by 2
    '*' - magical beans - strength increases by 5
    '#' - blockade - cannot go any further in his current row and 
                            simply jumps to the start of a new line 
                            without losing any strength.
    Each step takes 1 unit strength

    can move row wise towards right

    no str loss for travelling from last of one row to start of another

    At every time befor moving next step his strength must be greater than k

    escape is succesful if he returns with atleast k str remaining*/
    
   for(int i = 0; i<n; i++){
       for(int j = 0; j<m; j++){
            if(s-1>=k){
                if(j != m-1){
                    //not the end of the row
                    if(arr[i][j] == '.'){
                        s-=3;
                    }
                    else if(arr[i][j] == '*'){
                        s += 4;
                    }
                    else{
                        j = m;
                    }
                }else{
                    //end of the row
                    if(arr[i][j] == '.'){
                        s-=2;
                    }
                    else if(arr[i][j] == '*'){
                        s += 5;
                    }
                    else{
                        j = m;
                    }
                }
                
            }
           else{
               //cout<<s<<endl;
               return s;
           }
       }
       //s++;
   }
   //cout<<s<<endl;
   return s;

}
int main(){
    int n,m,k,s; //n rows m columns
    char park[100][100];
    cin>>n>>m>>k>>s;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>park[i][j];
        }
    }
    int x = helpPiyush(park,n,m,k,s);
    cout<<x<<endl;
    if(x>=k)  cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}