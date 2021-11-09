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
    
    void helper(TreeNode*root , int level , int &ans , int& x){
        
         if(root == NULL){
             return;
         }
        
        if(x < level){
            ans = root->val;
            x++;
        }
        
        helper(root->left , level + 1 , ans , x );
        
        helper(root->right , level + 1 , ans , x);
    }
    int findBottomLeftValue(TreeNode* root) {
        
       int ans;
       int x = 0; 
       helper(root , 1 , ans , x);
        
       return ans;
    }
};