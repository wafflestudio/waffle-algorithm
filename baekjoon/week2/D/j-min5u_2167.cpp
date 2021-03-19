#include<iostream>
using namespace std;
int main(){
    int n,m,arr[301][301]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    int cases;
    cin>>cases;
    for(int c=0;c<cases;c++){
        int i,j,x,y,sum=0;
        cin>>i>>j>>x>>y;
        for(int p=i;p<=x;p++){
            for(int q=j;q<=y;q++){
                sum+=arr[p][q];
            }
        }
        cout<<sum<<endl;
    }
}
//사실 dp로 푸는게 맞음,,