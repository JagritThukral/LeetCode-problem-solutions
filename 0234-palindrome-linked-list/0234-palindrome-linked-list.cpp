#include <stack>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // to get time complexity as o(n) and space complexity as o(1)
        // use fast and slow pointer
        // fast moves two steps at a time, slow moves one step
        // when fast reaches end aka n, 
        // 2k=n, k number of steps by slow pointer
        // k = n/2
        // i.e. k = the middle term = steps by slow pointer
        // if we get the middle term then compare halfs
        // odd n -> we get exact middle
        // even n -> we get start of second half
        ListNode* slow = head; 
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // to compare halfs
        // reverse second half
        ListNode* prev = nullptr;
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* s1 = head;
        ListNode* s2 = prev;

        while(s2){
            if (s1->val != s2->val) return false;
            s1=s1->next;
            s2=s2->next;
        }
        return true;
    };
};