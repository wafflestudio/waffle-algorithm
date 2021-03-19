#include<iostream>
using namespace std;

int main(){
    int n,inarr[51]={0},cntarr[51]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inarr[i];
    }
    for(int i=0;i<n-1;i++){

        cntarr[i]++;
        cntarr[i+1]++;
        double m=inarr[i+1]-inarr[i];
        for(int j=i+2;j<n;j++){
            double nextm=(inarr[j]-inarr[i])/((double)(j-i));
            if(nextm>m){
                cntarr[i]++;
                cntarr[j]++;
                m=nextm;
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(cntarr[i]>max) max=cntarr[i];
    }
    cout<<max<<endl;
}