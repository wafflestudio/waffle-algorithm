#include<iostream>
using namespace std;
int main(){
    int n,arr[10]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        int h,j=0;
        cin>>h;
        while(h>=0){
            if(arr[j]==0){
                h--;
            }
            j++;
        }
        arr[j-1]=i+1;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1) cout<<" ";
    }
}