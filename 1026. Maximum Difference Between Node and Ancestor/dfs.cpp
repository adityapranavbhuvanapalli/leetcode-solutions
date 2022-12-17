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
    int maxAncestorDiff(TreeNode* root) {
        // List of ancestors for the particular node
        vector<int> ancestors;
        return dfs(root, ancestors);
    }

    int dfs(TreeNode* root, vector<int>& ancestors) {
        if(!root)
            return 0;
        
        int maxVal = INT_MIN; 
        int val = root->val;
        for(auto& ancestor: ancestors)
            maxVal = max(maxVal, abs(ancestor - val));

        // Backtrack the list of ancestors
        ancestors.push_back(val);
        int l = dfs(root->left, ancestors);
        int r = dfs(root->right, ancestors);
        ancestors.pop_back();

        return max(maxVal, max(l, r));
    }
};