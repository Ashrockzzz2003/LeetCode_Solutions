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
    int getSize(ListNode* head) {
        int N = 0;
        ListNode* current_node = head;
        while(current_node) {
            current_node = current_node->next;
            N++;
        }
        return N;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = getSize(head);
        vector<ListNode*> final_list(k);

        int part_size = N / k;
        int part_count_to_add_extra_node = N % k;

        ListNode* current = head;
        ListNode* prev = current;

        for(int i = 0; i < k; i++) {
            ListNode* new_part = current;
            int current_size = part_size;

            if(part_count_to_add_extra_node > 0) {
                current_size++;
                part_count_to_add_extra_node--;
            }

            for(int j = 0; j < current_size; j++) {
                prev = current;
                if (current != NULL) current = current->next;
            }

            if (prev != NULL) prev->next = NULL;

            final_list[i] = new_part;
        }

        return final_list;
    }
};