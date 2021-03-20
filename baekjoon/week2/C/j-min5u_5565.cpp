#include<iostream>
using namespace std;
int main(){
    int sum,cost;
    cin>>sum;
    for(int i=0;i<9;i++){
        cin>>cost;
        sum-=cost;
    }
    cout<<sum<<endl;
}