// Approach -> 1
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==NULL || left == right){
            return head;
        }

        //ListNode dummy(0); 
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 

        // Move prev to node before the `left` position
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Now reverse the sublist between left and right
        ListNode* curr = prev->next;
        ListNode* next = NULL;

        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
