class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // 1: Save the future
            curr->next = prev;               // 2: Reverse the link
            
            prev = curr;                     // 3: Move prev forward
            curr = nextTemp;                 // 4: Move curr forward
        }
        
        return prev;
    }
};