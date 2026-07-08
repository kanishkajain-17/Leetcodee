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
        
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {

            fast = fast->next->next;

            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
            
        }

        if(fast) 
            slow = slow->next;
        
        while (slow != NULL) {

            if(prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};