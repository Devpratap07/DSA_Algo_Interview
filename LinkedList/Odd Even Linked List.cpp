//Approach ->1
//T.C ->O(n)
//S.C ->O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL && head->val){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenstart=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenstart;
        return head;
    }
};
