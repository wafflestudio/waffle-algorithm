#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyInefficientSolution {
public:
    bool isPalindrome(ListNode* head) {
        // inefficient solution
        // n: length of the list
        // time complexity: O(n)
        // space complexity: O(n)
        bool result = true;
        int list_length = 0;
        ListNode *temp = head;
        vector<ListNode*> nodeVec;
        
        while(temp) {
            nodeVec.push_back(temp);
            temp = temp->next;            
            list_length++;
        }
        
        int left = 0, right = list_length-1;
        while(left <= right) {
            if (nodeVec[left]->val != nodeVec[right]->val) {
                result = false;
                break;
            }
            left++;
            right--;
        }
        
        
        return result;
    }
};

class SmartSolution {
//ref: https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C++-solution
//time complexity still O(n)
public:
    bool check(ListNode* &head, ListNode *p) {
        if(p==NULL) {
            return true;
        }
        bool isPal = check(head, p->next);
        if (head->val != p->val) {
            return false;
        }
        head = head->next;
        return isPal;
    }
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
};