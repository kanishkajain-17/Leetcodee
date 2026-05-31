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
        int n = 0;
        ListNode* temp = head;
        ListNode* tail = head;
        while (temp != NULL) {
            n += 1;
            temp = temp->next;
            
        }
        while (tail->next != NULL)
            tail = tail->next;
        k = k % n;
        if(k == 0)  
            return head;
        temp = head;
        ListNode* prev = NULL;
        for (int i = 1; i <= n - k; i += 1) {

            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        tail->next = head;
        head = temp;
        
        return head;
    }

};