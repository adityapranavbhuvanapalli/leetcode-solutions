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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // p, q are both not there
        if(!p && !q)
            return true;

        // Either p is there or q is there
        if(!p ^ !q)
            return false;
        
        // If node is non-leaf
        return (p->val == q->val) 
        && isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right);
    }
};