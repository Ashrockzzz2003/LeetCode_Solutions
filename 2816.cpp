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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head;


        while (curr_node != nullptr) {
            ListNode* temp = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = temp;
        }

        return prev_node;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* reversed_list_head = reverseList(head);

        int c = 0;
        ListNode* curr_node = reversed_list_head;
        ListNode* prev_node = nullptr;

        while (curr_node != nullptr) {
            int new_val = curr_node->val * 2 + c;
            curr_node->val = new_val % 10;

            if (new_val > 9) c = 1;
            else c = 0;

            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        if (c != 0) {
            ListNode* extra_node = new ListNode(c);
            prev_node->next = extra_node;
        }

        ListNode* final_head = reverseList(reversed_list_head);
        return final_head;
    }
};