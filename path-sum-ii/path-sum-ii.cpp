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
    vector<vector<int>>ans;
    void helper(TreeNode*root ,int target ,int s ,vector<int>v){
        
         if(root == NULL){
             return;
         }
        s = s + root->val;
        v.push_back(root->val);
        
        if(s == target && root->left == NULL && root->right == NULL){
           ans.push_back(v);
           return;
        }
        helper(root->left , target , s , v);
        helper(root->right ,target, s , v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>p;
         helper(root , targetSum , 0 ,p );
        return ans;
    }
};