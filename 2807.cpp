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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current_node = head;
        ListNode* next_node = head->next;

        while (next_node != NULL) {
            ListNode* gcd_node = new ListNode(__gcd(current_node->val, next_node->val));
            current_node->next = gcd_node;
            gcd_node->next = next_node;

            current_node = next_node;
            next_node = next_node->next;
        }

        return head;
    }
};