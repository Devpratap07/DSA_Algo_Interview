// Approach -> 1
// T.C -> o(n)
// S.C -> O(n)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum=0;
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        mp[0]=dummy;
        while(head!=NULL){
            sum=sum+head->val;
            if(mp.find(sum)!=mp.end()){
                ListNode* start=mp[sum];
                ListNode* temp=start;
                int psum=sum;
                while(temp!=head){
                    temp=temp->next;
                    psum=psum+temp->val;
                    if(temp!=head){
                        mp.erase(psum);
                    }
                }
                start->next=head->next;
            }
            else{
                mp[sum]=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};
