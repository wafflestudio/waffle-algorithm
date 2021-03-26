//
// Created by Hank Choi on 2021/03/26.
//
// 0ms 7.4MB

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr)
  {}

  ListNode(int x) : val(x), next(nullptr)
  {}

  ListNode(int x, ListNode *next) : val(x), next(next)
  {}
};

class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *l = head;
    ListNode *iter = head->next;
    ListNode *r = head->next->next;
    head = head->next;
    while (r != nullptr && r->next != nullptr){
      l->next = r->next;
      iter->next = l;
      l = r;
      iter = r->next;
      r = iter->next;
    }
    if(r== nullptr){
      iter->next = l;
      l->next = nullptr;
    }
    else{
      iter->next = l;
      l->next = r;
      r->next = nullptr;
    }
    return head;
  }
};

int main(){
  ListNode* l1 = new ListNode(1, new ListNode(2,new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode* l2 = new ListNode(1, new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
  ListNode* result = Solution().swapPairs(l2);
  while(result != nullptr){
    cout << result->val;
    result = result->next;
  }
}