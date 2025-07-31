// Approach -> 1
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy->next;
        while(temp!=NULL&&temp->next!=NULL){
            if(temp!=NULL && temp->next!=NULL){
                swap(temp->val,temp->next->val);
            }
            temp=temp->next->next;
        }
        return dummy->next;
    }
};

// Approach -> 2
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0); // dummy node before head
        dummy->next = head;
        ListNode* prev = dummy;

        while (head != NULL && head->next != NULL) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping the nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Moving to the next pair
            prev = first;
            head = first->next;
        }

        return dummy->next;
    }
};

// Approach -> 3
// T.C -> O(n)
// S.C -> O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;
    }
};
