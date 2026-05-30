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
    //need to reverse the nodes 
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
    // void insert(int x, ListNode* &head, ListNode* &temp) {
    //     ListNode* node = new ListNode(x);
    //     if(head == NULL) {
    //         head = node;
    //         temp = node;
    //         return;
    //     }
    //     temp->next = node;
    //     temp = node;
    // }
    // ListNode* add(ListNode* l1, ListNode* l2) {
    //     int carry = 0;
    //     ListNode* head = NULL;
    //     ListNode* temp = NULL;

    //     while (l1 != NULL || l2 != NULL || carry != 0) {
    //         sum = carry;
            
    //         if(l1 != NULL) {
    //             sum += l1->val;
    //             l1 = l1->next;
    //         }
    //         if(l2 != NULL) {
    //             sum += l2->val;
    //             l2 = l2->next;
    //         }

            
    //         val = sum % 10;
    //         ListNode* newNode = new ListNode(val);
    //         tail->next = newNode;
    //         tail = newNode;
            
    //         carry = sum / 10;
    //     }
    //     return head;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        // ListNode* ans = add(l1, l2);
         ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int carry = 0;
        int sum = 0;
        int val = 0;
        
        while (l1 != NULL || l2 != NULL || carry != 0) {
            sum = carry;
            
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            
            val = sum % 10;
            ListNode* newNode = new ListNode(val);
            tail->next = newNode;
            tail = newNode;
            
            carry = sum / 10;
        }
       // return dummy->next;
       dummy = dummy->next;
       dummy = reverse(dummy);
        return dummy;        
    }
};