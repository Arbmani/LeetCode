#include <climits>
#include <cstddef>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

*/

class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode * next = head->next;
            head->next      = prev;
            prev            = head;
            head            = next;
        }
        return prev;
    }


public:
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxVal = INT_MIN;
        ListNode* cur   = head;
        ListNode* prev = nullptr;

        while(cur){
            if (cur->val < maxVal){
                prev->next = cur->next;
            }
            else{
                maxVal = cur->val;
                prev   = cur;
            }
            cur = cur->next;
        }
        return reverse(head);        
    }
};