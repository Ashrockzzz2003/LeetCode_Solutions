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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int t_r = 0, b_r = m - 1, l_c = 0, r_c = n - 1;

        while(head != NULL) {
            for(int c = l_c; c <= r_c && head; c++) {
                matrix[t_r][c] = head->val;
                head = head->next;
            }
            t_r++;

            for(int r = t_r; r <= b_r && head; r++) {
                matrix[r][r_c] = head->val;
                head = head->next;
            }
            r_c--;

            for(int c = r_c; c >= l_c && head; c--) {
                matrix[b_r][c] = head->val;
                head = head->next;
            }
            b_r--;

            for(int r = b_r; r >= t_r && head; r--) {
                matrix[r][l_c] = head->val;
                head = head->next;
            }
            l_c++;
        }

        return matrix;
    }
};