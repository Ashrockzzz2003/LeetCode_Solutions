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
    TreeNode* addOneRow(TreeNode* root, int value, int depth) {

        // Magically reduce run time
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        if (root == nullptr) {
            return root;
        }

        if (depth == 1) {
            return new TreeNode(value, root, nullptr);
        }

        if (depth == 2) {
            root->left = new TreeNode(value, root->left, nullptr);
            root->right = new TreeNode(value, nullptr, root->right);
            return root;
        }

        addOneRow(root->left, value, depth - 1);
        addOneRow(root->right, value, depth - 1);
        return root;
        
        // if (depth == 1) {
        //     return new TreeNode(value, root, nullptr);
        // }

        // dfsAndInsert(root, value, depth, 1);

        // return root;
        // exit case: empty tree
    }

    // void dfsAndInsert(TreeNode* root, int value, int depth, int current_depth) {
    //     if (root == nullptr) {
    //         return;
    //     }

    //     if (current_depth == depth - 1) {
    //         root->left = new TreeNode(value, root->left, nullptr);
    //         root->right = new TreeNode(value, nullptr, root->right);
    //         return;
    //     }

    //     dfsAndInsert(root->left, value, depth, current_depth + 1);
    //     dfsAndInsert(root->right, value, depth, current_depth + 1);
    // }
};