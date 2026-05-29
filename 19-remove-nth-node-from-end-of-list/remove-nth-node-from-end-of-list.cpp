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
        ListNode* temp = head;
        for (int i = 0; i < n; i += 1) {
            temp = temp->next;
        }
        if(temp == NULL) { //first node to be deleted
            ListNode* node_to_be_deleted = head;
            head = head->next;
            delete(node_to_be_deleted);
            return head;
        }
        ListNode* prev = head;
        while (temp != NULL && temp->next != nullptr) {
            prev = prev->next;
            temp = temp->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};