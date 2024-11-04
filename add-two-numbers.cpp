class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy;   
        int carry = 0;               

        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0; // Get the value of l1 or 0 if l1 is null
            int y = (l2 != nullptr) ? l2->val : 0; // Get the value of l2 or 0 if l2 is null

            int sum = x + y + carry; 
            carry = sum / 10;        

            current->next = new ListNode(sum % 10); 
            current = current->next; 

            if (l1 != nullptr) l1 = l1->next; // Move to the next node in l1
            if (l2 != nullptr) l2 = l2->next; // Move to the next node in l2
        }
        if (carry > 0) {
            current->next = new ListNode(carry); // If there's a carry, add a new node
        }

        return dummy->next; // Return the head of the new list
    }
};
