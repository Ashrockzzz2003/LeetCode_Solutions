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
    vector<string> all_possible_configurations;

    void traverse(TreeNode *root, string the_string) {
        if (root == nullptr) {
            return;
        }

        char x = root->val + 'a';

        if (root->left == nullptr && root->right == nullptr) {
            all_possible_configurations.push_back(x + the_string);
            return;
        }

        if (root->left != nullptr) {
            traverse(root->left, x + the_string);
        }

        if (root->right != nullptr) {
            traverse(root->right, x + the_string);
        }

    }

    string smallestFromLeaf(TreeNode* root) {
        traverse(root, "");
        sort(all_possible_configurations.begin(), all_possible_configurations.end());

        return all_possible_configurations[0];
    }
};