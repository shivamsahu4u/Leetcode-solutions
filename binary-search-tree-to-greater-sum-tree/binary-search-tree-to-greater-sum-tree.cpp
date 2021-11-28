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
    
  int helper(TreeNode* root , int &s){
        
         if(root == NULL){
           return s;
         }
        
          int r = helper(root->right , s);
       
          root->val = root->val + r;
        
         return helper(root->left , root->val);
      
    }
    TreeNode* bstToGst(TreeNode* root) {
        int s  = 0;
          helper(root , s);
        
        return root;
    }
};