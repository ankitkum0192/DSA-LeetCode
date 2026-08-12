class Solution {
public:
    ListNode* sortList(ListNode* head) {

       
        if (head == nullptr || head->next == nullptr)
            return head;

      
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

       
        ListNode* second = slow->next;
        slow->next = nullptr;

       
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left != nullptr && right != nullptr) {

            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        
        if (left != nullptr)
            curr->next = left;
        else
            curr->next = right;

        return dummy.next;
    }
};