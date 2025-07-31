// Approach -> 1
// T.C -> O(n)
// S.C -> O(k)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int total = 0;
        ListNode* temp = head;
        while (temp) {
            total++;
            temp = temp->next;
        }

        int partSize = total / k;
        int extra = total % k;

        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;

        for (int i = 0; i < k && curr != nullptr; i++) {
            result[i] = curr;
            int currentPartSize = partSize + (extra-- > 0 ? 1 : 0);

            for (int j = 1; j < currentPartSize; j++) {
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return result;
    }
};
