/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if (root == nullptr) {
            return 0;
        }

        int the_sum = 0;

        // if it's a left leaf
        if((root->left != nullptr) && (root->left->left == nullptr) && (root->left->right == nullptr)) {
            the_sum += root->left->val;
        }


        return sumOfLeftLeaves(root->left) + the_sum + sumOfLeftLeaves(root->right);
    }
};