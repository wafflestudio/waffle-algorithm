#include<iostream>
using namespace std;
int main(){
    string str;
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>str;
        int i=0,check=0;
        bool flag=true;
        while(str[i]!='\0'){
            if(str[i]=='(') check++;
            else check--;
            if(check<0){
                flag=false;
                break;
            }
            i++;
        }
        if(check==0&&flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}