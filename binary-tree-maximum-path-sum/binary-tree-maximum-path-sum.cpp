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
    
    int ans = INT_MIN;
    int helper(TreeNode*root){
        
        if(root == NULL){
            return 0;
        }
        
       int left = helper(root->left);
       int right = helper(root->right);
        
       int mlr = max(root->val + max(left ,right) , root->val);
        
       int ma = max(mlr , root->val + left + right);
        
       ans =  max(ans , ma);
        
       //see here we did not consider to get max(left , right) as they will already to be in ans , as this is postorder , we are going to left and right first , and at last we are comming back to root , so if left or right will  be max then they will be present in answer only 
       return mlr; 
    }
    int maxPathSum(TreeNode* root) {
       //## tricky question
        
        helper(root);
       return ans; 
    }
};