/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (head == NULL) {
            return false;
        }

        if (head->next == NULL) {
            return false;
        }

        if (head == head->next) {
            return true;
        }

        ListNode *currentNode = head;
        while (currentNode->next != NULL) {
            currentNode->val = 100001;

            if (currentNode->next != NULL && currentNode->next->val == 100001) {
                return true;
            }
            currentNode = currentNode->next;
        }

        return false;

    }
};