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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maxSum = 0;

        //1. find mid
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //2. reverse the second half of the ll
        ListNode* prev = NULL;
        ListNode* mid = slow;
        ListNode* next = NULL;

        while (mid != NULL) {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }

        //3. calculate sum
       ListNode*  cur = head;
        while(prev != NULL){ //prev is new head of reverse ll
            maxSum = max(maxSum, cur->val + prev->val);
            cur = cur->next;
            prev = prev->next;
        }
        return maxSum;
    }
};