class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(list1, list2));
            }
            
            lists = mergedLists;
        }
        
        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1 != nullptr) tail->next = l1;
        if (l2 != nullptr) tail->next = l2;
        
        return dummy.next;
    }
};