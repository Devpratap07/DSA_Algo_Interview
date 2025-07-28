//Approach -> 1
// T.C -> O(n)  // you loop until the end of the list
// S.C -> O(1)  // no extra space used
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev=NULL;
        while(node!=NULL && node->next!=NULL){
            node->val=node->next->val;
            prev=node;
            node=node->next;
        }
        prev->next=NULL;
        delete(node);
    }
};

//Approach ->2
// T.C -> O(1)
// S.C -> O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* temp;
        temp = node->next;
        node->next=temp->next;
        delete(temp);
    }
};
