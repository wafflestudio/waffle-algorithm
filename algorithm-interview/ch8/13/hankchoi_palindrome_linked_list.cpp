//
// Created by Hank Choi on 2021/03/26.
//
// 184ms 128.1MB
#include <vector>

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
  bool isPalindrome(ListNode* head) {
    vector<int> stack;
    ListNode* iter=head;
    while(iter != nullptr){
      stack.push_back(iter->val);
      iter=iter->next;
    }
    int r = stack.size()-1;
    int l = 0;
    while(l<r){
      if(stack[l] != stack[r])
        return false;
      r--;
      l++;
    }
    return true;
  }
};
