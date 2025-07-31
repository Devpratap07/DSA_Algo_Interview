//Approach ->1
//T.C ->o(N log N) because finding the middle takes O(N), and you do it for log N levels of recursion (in a balanced tree).
//S.C ->o(N)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return new TreeNode(head->val); 
        }
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL&& fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);

        prev->next=NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};

//Approach ->2
// T.C -> O(n)
// S.C -> O(n)
class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }
        return buildBST(values, 0, values.size() - 1);
    }
};
