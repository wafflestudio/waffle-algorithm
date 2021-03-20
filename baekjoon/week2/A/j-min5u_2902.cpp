#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    int i=1;
    cout<<str[0];
    while(str[i]!='\0'){
        if(str[i]=='-'){
            cout<<str[i+1];
        }
        i++;
    }



}