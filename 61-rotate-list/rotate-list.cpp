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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int size = 0;
        ListNode* temp = head;

        while (temp != NULL) {

            size += 1;
            temp = temp->next;
        }

        k = k % size;

        if(k == 0)
            return head;
        
        int n = size - k;

        temp = head;
        for (int i = 1; i < n; i ++) {

            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* newTemp = newHead;

        while (newTemp->next != NULL) {
            newTemp = newTemp->next;
        }

        newTemp->next = head;
        return newHead;
    }
};