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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            size += 1;
            temp = temp->next;
        }
        temp = head;
        n = size - n + 1;
        if(n == 1){
            head = head->next;
            return head;
        }
        ListNode* prev = temp;
        for (int i = 1; i < n; i += 1) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return head;
    }
};