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
    
    void helper(TreeNode*root , int &s , string d){
        
        if(root == NULL){
            return;
        }
        
        d = d + to_string(root->val);
        
        if(root->left == NULL &&  root->right == NULL){
            s = s + stoi(d);
            return;
        }
        
        helper(root->left , s , d);
        
        helper(root->right , s , d);
    }
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        
        helper(root , ans , "");
        
        return ans;
    }
};