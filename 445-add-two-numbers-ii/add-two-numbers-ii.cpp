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
    ListNode* reverse(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nextt = NULL;
        
        while (cur != NULL) {
            nextt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextt;
        }
        return prev;
        
    }
    void insert(int x, ListNode* &head, ListNode* &temp) {
        ListNode* node = new ListNode(x);
        if(head == NULL) {
            head = node;
            temp = node;
            return;
        }
        temp->next = node;
        temp = node;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = NULL;
        ListNode* temp = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int val1 = 0;
            if(l1 != NULL)
                val1 = l1->val;

            int val2 = 0;
            if(l2 != NULL)
                val2 = l2->val;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            insert(digit, head, temp);

            carry = sum / 10;

            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* ans = add(l1, l2);
        ans = reverse(ans);
        return ans;        
    }
};