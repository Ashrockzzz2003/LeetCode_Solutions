/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* updateToNode = head->next;
        ListNode* nextSum = updateToNode;

        while (nextSum) {
            int sum = 0;

            while (nextSum->val != 0) {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }

            updateToNode->val = sum;
            nextSum = nextSum->next;
            updateToNode->next = nextSum;
            updateToNode = updateToNode->next;
        }

        return head->next;
    }
};