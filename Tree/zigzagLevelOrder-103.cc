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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }

        vector<TreeNode*> stack{root};
        vector<TreeNode*> stack2;
        bool fromLeftToRight = true;

        while (stack.size()) {
            vector<int> v;
            stack2.clear();
            for (int i = stack.size()-1; i >= 0; --i) {
                v.push_back(stack[i]->val);
                if (fromLeftToRight) {
                    if (stack[i]->left)
                        stack2.push_back(stack[i]->left);
                    if (stack[i]->right)
                        stack2.push_back(stack[i]->right);
                } else {
                    if (stack[i]->right)
                        stack2.push_back(stack[i]->right);
                    if (stack[i]->left)
                        stack2.push_back(stack[i]->left);
                }
            }
            res.push_back(v);
            fromLeftToRight = !fromLeftToRight;
            swap(stack, stack2);
        }
        return res;
    }

    vector<vector<int>> res;
};
