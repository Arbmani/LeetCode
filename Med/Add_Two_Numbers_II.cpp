#include "stack"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**

You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        stack<int> s1, s2;
        int carry = 0;
        while(l1 || l2){
            if (l1){
                s1.push(l1->val);
                l1 = l1->next;
            }
            if (l2){
                s2.push(l2->val);
                l2 = l2->next;
            }
        }
        while(!s1.empty() || !s2.empty() || carry){
            int sum = carry;
            if (!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = result;
            result     = node;
        }
        return result;
    }
};