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
    
    pair<int , bool> helper(TreeNode*root){
        
        pair<int , bool>ans;
        
        if(root == NULL){
            ans.first = 0;
            ans.second = true;
            return ans;
        }
        
        pair<int , bool>ans1 = helper(root->left);
        
        pair<int , bool>ans2 = helper(root->right);
        
        ans.first = max(ans1.first , ans2.first) + 1;
        if(ans1.second == false || ans2.second == false){
            ans.second = false;
            return ans;
        }
        
        if(abs(ans1.first- ans2.first) > 1){
           ans.second = false;
            return ans;
        }
         ans.second = true;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        
        return helper(root).second;
    }
};