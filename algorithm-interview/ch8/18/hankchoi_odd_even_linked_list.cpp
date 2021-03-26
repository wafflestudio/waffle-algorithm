//
// Created by Hank Choi on 2021/03/27.
//
//8ms 10.5MB

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
    ListNode* odd=head;
    ListNode* even=head->next;
    ListNode* even_start = head->next;
    while(even->next != nullptr && even->next->next != nullptr){
      odd->next=even->next;
      even->next=even->next->next;

      odd = odd->next;
      even = even->next;
    }
    if(even->next != nullptr){
      odd->next = even->next;
      odd = odd->next;
      even->next = nullptr;
    }
    odd->next = even_start;
    return head;
  }
};
