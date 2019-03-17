/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int l=0, r=0;
        if(!root)
            return true;
        l = TreeDepth(root->left);
        r = TreeDepth(root->right);
        if(abs(l-r) > 1)
            return false;
        else
        {
            if(isBalanced(root->left) && isBalanced(root->right))
                return true;
            return false;
        }
        
    }
    int TreeDepth(TreeNode* root)
    {
         if(!root)
            return 0;
         return max(TreeDepth(root->left), TreeDepth(root->right)) + 1;    
    }
   
};