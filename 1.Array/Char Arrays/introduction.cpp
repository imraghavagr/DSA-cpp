#include<iostream>
using namespace std;
 /*
        Writing our own cin.getline func, using cin.get() which reads a single character
*/
void readLine(char a[], int maxLen, char delim = '\n'){
    int i = 0;
    char ch = cin.get();
    while(ch != delim){
        a[i++] = ch;
        if(i == maxLen)break;
        ch = cin.get();

    }
    a[i] = '\0';
    return;
}
int main(){

    char a[100]; // declaration

    char b[] = {'a', 'b', 'c', '\0'}; //right. Total size = 4 bytes.
    //char c[] = {'a','b','c'}; wrong.. garbage value will be inserted at the end.
    char c[10] = {'a','b','\0'};// remaining elements will be garbage
    cout<<b<<endl<<c<<endl;

    //diff bw int  and char array (operator (<<)overloading)
    int x[] ={1,2,3,4,5};
    cout<<x<<endl; // this will print the starting addr of the array.
    cout<<b<<endl; // this will print the contents of the array untill null is encountered.

    //input
    cin>>a; //"hello" -  this will be stored as "hello\0" in the memory
    cout<<a<<endl;

    char s[10];
    cin>>s; // "hello world"
    cout<<s<<endl; //"hello"-  as soon as spacd or new line will come. cin will stop reading in such case we will use cin.getlin();

    char s1[100];
    cin.getline(s1,100,'*'); //will read untill '*' is encountered
    //cin.getline(s1,100); - default delem is '\n'
    cout<<s1<<endl;

    char s2[100];
    readLine(s2,100,'*');
    cout<<s2<<endl;  

    return 0;
}