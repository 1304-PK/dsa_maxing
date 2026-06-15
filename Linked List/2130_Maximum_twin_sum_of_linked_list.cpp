/*
Optimal approach, find middle, reverse from middle and then calculate max twin sum linearly

TC - O(N)
SC - O(1)
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *temp;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        temp->next = prev;
        temp = head;
        int sum = 0;
        while(prev){
            sum = max((prev->val) + (temp->val), sum);
            temp = temp->next;
            prev = prev->next;
        }
        return sum;

    }
};

/*
Optimal approach with better time optimization

Instead of reversing, it stores the traversed elements in a vector(instead of reversing) and then uses just one another loop to calculate twin sum

TC - O(N)
SC - O(1)
*/

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> half;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            half.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int res = 0;
        int i = half.size() - 1;

        while (slow) {
            res = max(res, half[i--] + slow->val);
            slow = slow->next;
        }

        return res;
    }
};