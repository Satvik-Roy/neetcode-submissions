class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* clonedHead = head->next;
        Node* cloneCurr = clonedHead;
        
        while (curr) {
            curr->next = curr->next->next;
            if (cloneCurr->next) {
                cloneCurr->next = cloneCurr->next->next;
            }
            
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return clonedHead;
    }
};