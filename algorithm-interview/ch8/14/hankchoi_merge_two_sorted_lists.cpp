//
// Created by Hank Choi on 2021/03/26.
//
//0ms 14.9MB

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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *iter1 = l1;
    ListNode *iter2 = l2;
    ListNode *merged_list = new ListNode();
    ListNode *ml_iter = merged_list;
    while (iter1 != nullptr && iter2 != nullptr) {
      if (iter1->val > iter2->val) {
        ml_iter->next = new ListNode(iter2->val);
        ml_iter = ml_iter->next;
        iter2 = iter2->next;
      } else {
        ml_iter->next = new ListNode(iter1->val);
        ml_iter = ml_iter->next;
        iter1 = iter1->next;
      }
    }
    if(iter1 != nullptr)
      ml_iter->next = iter1;
    else if (iter2!= nullptr)
      ml_iter->next = iter2;
    return merged_list->next;
  }
};