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
    int deep(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        return 1 + max(deep(root->left) , deep(root->right));
    }
    int ans = 0;
    
    void helper(TreeNode* root , int h){
        
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL && h == 1){
             ans = ans + root->val;
            return;
        }
        
        helper(root->left , h-1);
        helper(root->right , h - 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        int h = deep(root);
        cout<<h<<endl;
        helper(root , h);
        return ans;
    }
};