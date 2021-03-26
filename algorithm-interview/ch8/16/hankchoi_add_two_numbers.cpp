//
// Created by Hank Choi on 2021/03/26.
//
//24ms 71.1MB
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* iter1=l1;
    ListNode* iter2=l2;
    ListNode* new_list = new ListNode();
    ListNode* new_list_iter = new_list;
    int overflow = 0;
    while(iter1 != nullptr && iter2 != nullptr){
      int val = iter1->val + iter2->val + overflow;
      if (val > 9){
        overflow = 1;
        val -= 10;
      }
      else
        overflow = 0;
      new_list_iter->next = new ListNode(val);

      new_list_iter = new_list_iter->next;
      iter1 = iter1->next;
      iter2 = iter2->next;
    }
    while(iter1!= nullptr){
      int val = iter1->val + overflow;
      if (val > 9){
        overflow = 1;
        val -= 10;
      }
      else
        overflow = 0;
      new_list_iter->next = new ListNode(val);
      iter1 = iter1->next;
      new_list_iter = new_list_iter->next;
    }
    while(iter2!= nullptr){
      int val = iter2->val + overflow;
      if (val > 9){
        overflow = 1;
        val -= 10;
      }
      else
        overflow = 0;
      new_list_iter->next = new ListNode(val);
      iter2 = iter2->next;
      new_list_iter = new_list_iter->next;
    }
    if(overflow == 1)
      new_list_iter->next = new ListNode(1);
    return new_list->next;
  }
};

int main(){
  ListNode* l1 = new ListNode(9, new ListNode(9,new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
  ListNode* l2 =  new ListNode(9,new ListNode(9, new ListNode(9, new ListNode(9))));
  ListNode* result = Solution().addTwoNumbers(l1,l2);
  while(result != nullptr){
    cout << result->val;
    result = result->next;
  }
}