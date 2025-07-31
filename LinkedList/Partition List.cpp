// Approach -> 1
// T.C ->O(n)
// S.C ->O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* smallp=small;
        ListNode* largep=large;
        while(head!=NULL){
            if(head->val>=x){
                largep->next=head;
                largep=largep->next;
            }
            else{
                smallp->next=head;
                smallp=smallp->next;
            }
            head=head->next;
        }
        largep->next=NULL;
        smallp->next=large->next;
        return small->next;
    }
};
