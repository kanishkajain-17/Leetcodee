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
    ListNode* sortList(ListNode* head) {
        vector<int> sorted_values;
        ListNode* temp = head;
        while (temp != NULL) {
            sorted_values.push_back(temp->val);
            temp = temp->next;
        }
        sort(begin(sorted_values), end(sorted_values));
        temp = head;
        for (int i = 0; i < sorted_values.size(); i += 1) {
            temp->val = sorted_values[i];
            temp = temp->next;
        }
        return head;
    }
};