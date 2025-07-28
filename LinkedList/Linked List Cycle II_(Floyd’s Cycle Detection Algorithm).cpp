//Approach ->1
//(also known as the Tortoise and Hare Algorithm) 
//and finds the starting node of the cycle in a linked list
//T.C -> O(n)
//S.C -> O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* present=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(slow!=fast){
            return NULL;
        }
        while(present!=slow){
            present=present->next;
            slow=slow->next;
        }
        return present;
    }
};

//Approach ->2(Brute's force)
//T.c ->O(n)
//S.C ->O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        unordered_set<ListNode*> visited;
        ListNode* curr=head;
        while(curr!=NULL){
            if(visited.find(curr)!=visited.end()){
                return curr;
            }
            visited.insert(curr);
            curr=curr->next;
            }
            return NULL;
        }
};
