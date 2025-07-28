//Approach ->1
//T.C ->O(n)
//S.C ->O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next !=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
            return slow;
        }
};
