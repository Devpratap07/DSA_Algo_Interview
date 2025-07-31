// Approach -> 1
// T.C ->O(n)
// S.C ->O(n)
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        int sum=0;
        int carry=0;
        ListNode* ans=new ListNode();
        while(l1!=NULL || l2!=NULL){
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ans->val=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(carry);
            newNode->next=ans;
            ans=newNode;
            sum=carry;
        }
        return carry==0?ans->next:ans;
    }
};

// Approach -> 2
// T.c ->O(n+m)
// S.C ->O(n+m)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
