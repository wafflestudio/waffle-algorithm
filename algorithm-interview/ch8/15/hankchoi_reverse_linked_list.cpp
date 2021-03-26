//
// Created by Hank Choi on 2021/03/26.
//
// 8ms 8.3MB

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr)
      return head;
    ListNode* l = nullptr;
    ListNode* iter = head;
    ListNode* r = head->next;
    while(r != nullptr){
      iter->next=l;
      l=iter;
      iter=r;
      r = r->next;
    }
    iter->next=l;
    return iter;
  }
};