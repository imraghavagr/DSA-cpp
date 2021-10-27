#include<iostream>
#include<cstring>
using namespace std;
int main(){

    char a[1000] = "apple";
    char b[1000];

    //calc lenght
    cout<<strlen(a)<<endl;

    //strcpy
    strcpy(b,a); // a will be copied into b
    cout<<b<<endl;

    //compare
    cout<<strcmp(a,b)<<endl;

    //concatenate
    char web[] = "www.";
    char domain[] = "kuchnahi.com";
    //cout<<strcat(web,domain)<<endl;
    strcpy(b,strcat(web,domain));
    cout<<b<<endl;

    //now compare
    cout<<strcmp(a,b)<<endl;
    
    return 0;
}