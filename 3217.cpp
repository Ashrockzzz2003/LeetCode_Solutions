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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> to_remove;
        for(auto n : nums) to_remove.insert(n);
        ListNode* modified_list = NULL;
        while(head != NULL && to_remove.find(head->val) != to_remove.end()) {
            head = head->next;
        }

        ListNode* temp = head;
        ListNode* prev = head;

        while (temp != NULL) {
            if (to_remove.find(temp->val) != to_remove.end()) {
                prev->next = temp->next;
                temp = temp->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};