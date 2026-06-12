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

/*
Iterative approach

Check for either l1, l2 or carry and then calculate sum and carry accordingly

Dummy head and tail are used for maintaing linked list for the sum
*/

class Solution {
public:

    ListNode *reverseLL(ListNode *head){
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        int carry = 0;
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;
        while(l1 || l2 || carry){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            ListNode *temp = new ListNode(sum%10);
            tail->next = temp;
            tail = temp;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        dummyHead = reverseLL(dummyHead->next);
        return dummyHead;
    }
};
