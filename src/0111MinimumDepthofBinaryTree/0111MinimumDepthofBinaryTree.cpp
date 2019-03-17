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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left && root->right)
        return min(minDepth(root->left), minDepth(root->right)) + 1;
        else if(root->left && !root->right)
            return minDepth(root->left) + 1;
         else
            return minDepth(root->right) + 1;            
        
    }
};
//[1,2]的返回结果是2
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量