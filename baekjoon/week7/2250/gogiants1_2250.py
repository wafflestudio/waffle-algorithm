import sys
from collections import deque

N=int(sys.stdin.readline())
tree=[ [] for _ in range(N+1)] # 트리
isRoot = [0]*(N+1) # 루트인지 확인하기.
distance= [[] for _ in range(N+1)] # 레벨의 노드들 방문 순서 저장
root=0
for _ in range(N):
    par,l,r=map(int, sys.stdin.readline().rstrip().split())
    tree[par].append(l)
    tree[par].append(r)
    isRoot[par]+=1
    if l!=-1:
        isRoot[l]+=1
    if r!=-1:
        isRoot[r]+=1
        
for i in range(1,N+1): # root는 isRoot값이 1
    if isRoot[i]==1:
        root=i

num=1

def inorder(start,level): #level 레벨에 관련된 값, num은 구하려는 거리?.
    global num
    if tree[start][0]!=-1: # left is not null
        inorder(tree[start][0],level+1) #왼쪽 노드 먼저 방문
    distance[level].append(num) # 현재 노드 방문했다고 표시
    num+=1 
    if tree[start][1]!=-1: # 오른쪽 노드 방문
        inorder(tree[start][1],level+1)
 
inorder(root,1)
lev=1

ans= max(distance[1])-min(distance[1])+1
for i in range(2,N+1):
    if distance[i]:
        small=min(distance[i]) ## 각 층마다의 거리를 계산하여 최댓값인지 확인한다.
        large=max(distance[i])
        if ans<large-small+1:
            ans=large-small+1
            lev=i
print(lev,ans) 