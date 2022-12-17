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
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxVal;
    }

    int dfs(TreeNode* root){
        if(!root)
            return 0;

        int v = root->val;
        int l = dfs(root->left);
        int r = dfs(root->right);

        // maxVal of the particular node will be max of {v, v+l, v+r, v+l+r}
        maxVal = max({maxVal, v, v + max({l, r, l+r})});

        // while returning, we have to return only one path.
        // either / or \ or the node alone whichever is maximum
        // v+l+r has 2 paths i.e., /\ 
        // so it becomes max of v, v+l, v+r
        return max(v, v + max(l, r));
    }
};