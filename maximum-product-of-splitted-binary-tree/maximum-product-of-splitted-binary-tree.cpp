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
    int sum(TreeNode*root){
        if(root == NULL)return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    
    int helper(TreeNode* root , long long sum , long long &ans){
        
         if(root == NULL){
             return 0;
         }
        
        int s= helper(root->left , sum , ans) + helper(root->right , sum  , ans) + root->val;
        
        ans = max(ans , (sum - s)*s);
      
         return s;
    }
    int maxProduct(TreeNode* root) {
        
        long long  ans = 0;
        long long s = sum(root);
        helper(root , s , ans);
        
        return ans% 1000000007;
    }
};