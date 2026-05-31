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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        //check if k nodes exists
        while (count < k) {
            if(temp == NULL)
                return head;
            temp = temp->next;
            count += 1;
        }

        //recursively call for the rest of ll
        ListNode* newHead = reverseKGroup(temp, k);
        
        //reverse cuurent group
        temp = head;
        count = 0;
        while (count <  k) {
            ListNode* next = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = next;
            count += 1;
        }
        return newHead;
    }
};