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
    
    void helper(TreeNode* root , int &ans , TreeNode* &pre){
        
        if(root == NULL) return ;
        
        helper(root->left , ans , pre);
        if(pre)
        ans = min(ans , abs(pre->val - root->val));
        pre = root;
        helper(root->right , ans , pre);
    }
    int minDiffInBST(TreeNode* root) {
     
         int ans = INT_MAX;
        TreeNode* pre = NULL;
         helper(root , ans , pre);
         return ans;
    }
};