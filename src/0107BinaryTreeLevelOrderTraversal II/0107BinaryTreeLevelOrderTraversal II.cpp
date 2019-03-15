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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        stack<vector<int>> s;
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *last = root, *nlast = root;
        while(!q.empty())
        {
            TreeNode* t = q.front();
            ret.push_back(t->val);
            q.pop();
            if(t->left)
            {
                q.push(t->left);
                nlast = t->left;
            }
            if(t->right)
            {
                q.push(t->right);
                nlast = t->right;
            }
            if(t == last)
               {
                  // res.push_back(ret);
                   s.push(ret);
                   ret.clear();
                   last = nlast;
               }
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
       return res; 
        
    }
};