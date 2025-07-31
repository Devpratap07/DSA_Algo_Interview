// Approach -> 1
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int result=0;
        int i=0;
        int j=vec.size()-1;
        while(i<j){
            result=max(result,vec[i]+vec[j]);
            i++;
            j--;
        }
        return result;
    }
};

// Approach -> 2
// T.C -> O(n)
// S.C -> O(n)
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr=head;
        while(curr!=NULL){
            st.push(curr->val);
            curr=curr->next;
        }
        int n=st.size();
        curr=head;
        int count=1;
        int result=0;
        while(count<=n/2){
            result=max(result,curr->val+st.top());
            count++;
            curr=curr->next;
            st.pop();
        }
        return result;
    }
};

// Approach -> 3
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;;
        }
        ListNode* mid =slow;
        ListNode* prev=NULL;
        ListNode* nextNode=NULL;
        while(mid!=NULL){
            nextNode=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextNode;
        }
        int result =0;
        ListNode* curr=head;
        while(prev!=NULL){
            result =max(result,curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return result;
    }
};
