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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);

        while (true) {
            if (q.empty())
                break;

            queue<TreeNode*> q2;
            vector<int> v;
            while (q.size()) {
                auto f = q.front();
                q.pop();
                v.push_back(f->val);
        
                if (f->left)
                    q2.push(f->left);
                if (f->right)
                    q2.push(f->right);
            }
            res.push_back(v);
            swap(q, q2);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
