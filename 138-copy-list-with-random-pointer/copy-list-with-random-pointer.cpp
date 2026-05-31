/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

        Node* cur = head;

        //1. insert the new nodes btw the ll
        while (cur != NULL) {
            Node* curNext = cur->next; //B
            cur->next = new Node(cur->val); // A -> B
            cur->next->next = curNext; //A -> x -> B
            cur = curNext;
        }

        //2. deep copy of random pointers
        cur = head;
        while (cur != NULL && cur->next != NULL) {
            if(cur->random == NULL)
                cur->next->random = NULL;
            else
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        //3. seprate the ll
        Node* newHead = head->next; //to be return head
        Node* newCur  = newHead; //pointing to self made ll
        cur           = head; //pointing to original

        while (cur != NULL && newCur != NULL) {
            cur->next = (cur->next == NULL) ? NULL : cur->next->next;
            newCur->next = (newCur->next == NULL) ? NULL : newCur->next->next;

            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;
    }
};