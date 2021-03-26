//
// Created by Hank Choi on 2021/03/27.
//
//4ms 7.5MB
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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    if (left == right) return head;
    int index = 0;
    ListNode *iter = new ListNode(0, head);
    head = iter;
    ListNode *left_node;
    ListNode *left_node_before;
    while (index < left - 1) {
      iter = iter->next;
      index++;
    }
    left_node_before = iter;
    iter = iter->next;
    index++;
    left_node = iter;
    ListNode *pre = nullptr;
    while (index <= right) {
      ListNode *post = iter->next;
      iter->next = pre;
      pre = iter;
      iter = post;
      index++;
    }
    left_node_before->next = pre;
    left_node->next = iter;
    return head->next;
  }
};

