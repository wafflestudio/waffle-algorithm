#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> e[1001];
bool chk[1001];

void dfs(int x){
	chk[x]=true;
	printf("%d ", x);
	for(auto a:e[x]) if(!chk[a]) dfs(a);
}

int main(){
	int N, M, V;
	int a, b;
	queue<int> q;

	scanf("%d%d%d", &N, &M, &V);
	for(int i=0; i<M; i++){
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	for(int i=1; i<=N; i++) sort(e[i].begin(), e[i].end());

	dfs(V);
	printf("\n");
	for(int i=1; i<=N; i++) chk[i]=false;
	q.push(V);
	chk[V]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		printf("%d ", t);
		for(auto a:e[t]) if(!chk[a]){
			chk[a]=true;
			q.push(a);
		}
	}

	return 0;
}
