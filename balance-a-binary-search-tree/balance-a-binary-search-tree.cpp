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
    
    void helper(TreeNode*root , vector<int>&ans){
        
        if(root == NULL){
            return ;
        }
        
        helper(root->left , ans);
        ans.push_back(root->val);
        helper(root->right , ans);
    }
    TreeNode* buildTree(vector<int>&ans , int s , int e){
        
        if(s > e)
            return NULL;
        
        int mid = (s + e)/2;
        
        TreeNode* root = new TreeNode(ans[mid]);
        
        root->left = buildTree(ans , s , mid - 1);
        root->right = buildTree(ans , mid + 1 , e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
         vector<int>ans;
        helper(root , ans);
        
        return buildTree(ans , 0 , ans.size() - 1);
    }
};