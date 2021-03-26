//
// Created by Hank Choi on 2021/03/27.
//

#include <iostream>
#include <tuple>

using namespace std;

class Balloon
{
public:
  Balloon *prev;
  Balloon *next;
  int val;
  int index;
  Balloon(int i, int v) : prev(this), next(this), val(v), index(i){}
  Balloon(int i, int v, Balloon *prev, Balloon *next) : prev(prev), next(next), val(v), index(i){}

  tuple<int,int> pop(){
    prev->next = this->next;
    next->prev = this->prev;
    return {index,val};
  }
};

int main()
{
  int N;
  int b;
  Balloon *head = new Balloon(-1, 5);
  tuple<int,int> popped;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> b;
    Balloon* new_balloon = new Balloon(i, b, head->prev, head);
    head->prev->next=new_balloon;
    head->prev = new_balloon;
  }
  Balloon *iter = head->next;
  head->pop();
  while (iter->next != iter) {
    popped = iter->pop();
    printf("%d ",get<0>(popped));
    int move = get<1>(popped);
    while(move<0){
      iter = iter->prev;
      move++;
    }
    while(move>0){
      iter = iter->next;
      move--;
    }
  }
  printf("%d",iter->index);
}