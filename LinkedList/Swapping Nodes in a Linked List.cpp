// Approach -> 1
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* fast = head;
        for (int i = 1; i < k; i++) {
            fast = fast->next;
        }

        ListNode* second = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            second = second->next;
        }

        swap(first->val, second->val);
        return head;
    }
};

// Approach -> 2
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        ListNode* reversed = reverseList(head);
        ListNode* second = reversed;
        for (int i = 1; i < k; i++) {
            second = second->next;
        }
        swap(first->val, second->val);
        reverseList(reversed); 
        return head;
    }
};

// Approach -> 3
// T.C -> O(n)
// S.C -> O(1)
class Solution {
public:
int findlength(ListNode* head){
    int l=0;
    while(head){
        head=head->next;
        l++;
    }
    return l;
}
    ListNode* swapNodes(ListNode* head, int k) {
        int L=findlength(head);
        int k_1 = k;
        ListNode* temp=head;
        while(k_1>1){
            temp=temp->next;
            k_1--;
        }
        ListNode* temp1=head;
        int k_2=L-k+1;
        while(k_2>1){
            temp1=temp1->next;
            k_2--;
        }
        swap(temp->val,temp1->val);
        return head;
    }
};
