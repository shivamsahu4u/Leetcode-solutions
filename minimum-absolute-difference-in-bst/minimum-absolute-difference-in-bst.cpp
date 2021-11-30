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

    void helper(TreeNode* root , int &ans, int &val){
        
        if(root == NULL) return;
        //go to left and find the minimum one
        helper(root->left , ans , val);
        if(val!=-1)
        ans = min(ans , abs(root->val - val));
        val = root->val;
        helper(root->right , ans , val);
    }
    int getMinimumDifference(TreeNode* root) {
        
        int ans = INT_MAX ; int val = -1;
        helper(root , ans , val); 
        return ans;
    }
};