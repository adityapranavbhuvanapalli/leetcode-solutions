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
    int mod = pow(10, 9) + 7;
    long maxVal = 0, sum = 0;
    int maxProduct(TreeNode* root) {
        // Find total sum of tree
        sum = treeSum(root);

        // Find the max product
        treeSum(root);
        return maxVal % mod;
    }

    int treeSum(TreeNode* root) {
       if(!root)
            return 0;
        
        int val = root->val;
        int lSum = treeSum(root->left);
        int rSum = treeSum(root->right); 

        // Compute the max product value
        maxVal = max({maxVal, lSum * (sum-lSum), rSum * (sum-rSum)});   

        // Return the sum
        return lSum + rSum + val;
    }
};