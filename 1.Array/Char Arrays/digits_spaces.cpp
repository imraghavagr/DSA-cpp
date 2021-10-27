#include<iostream>
using namespace std;
//given an sentence, count the number of digits, alphabets, spaces in it.
int main(){
    //lets read each char one by one
    char ch;
    ch = cin.get();
    int digits = 0;
    int spaces = 0;
    int chars = 0;
    while(ch!='\n'){
        if(ch>='0' and ch<='9') digits++;
        else if(ch == ' ' or ch == '\t')   spaces++;
        else if(ch>='a' and ch<='z' or ch>='A' and ch<='Z')  chars++;
        ch = cin.get();
    }
    cout<<"Total digits = "<<digits<<endl;
    cout<<"Total spaces = "<<spaces<<endl;
    cout<<"Total alphabets = "<<chars<<endl;

    return 0;
}