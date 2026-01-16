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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3main = new ListNode();
        ListNode* l3 = l3main;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int value1 = (l1 != nullptr) ? l1->val : 0;
            int value2 = (l2 != nullptr) ? l2->val : 0;
                    // div 10
                    // quotient -> carried
                    // remainder -> value
            int sum =  value1 + value2 +carry;
            carry = sum / 10;
            l3 -> val = sum % 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
           if (l1 != nullptr || l2 != nullptr || carry != 0) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }
        return l3main;
    }
};