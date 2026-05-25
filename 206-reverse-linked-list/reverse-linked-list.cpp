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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevv = NULL;
        ListNode* cur = head;
        ListNode* nextt = NULL;

        while (cur != NULL) {
            nextt = cur->next;
            cur->next = prevv;

            prevv = cur;
            cur = nextt;
        }
        return prevv;
    }
};