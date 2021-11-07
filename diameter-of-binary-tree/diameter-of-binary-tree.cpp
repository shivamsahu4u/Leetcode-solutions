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
    
    pair<int , int> helper(TreeNode* root){
        
        if(root == NULL){
            pair<int, int>ans;
            ans.first = 0;
            ans.second = 0;
            return ans;
        }
        
         pair<int , int>ans1 = helper(root->left);
        
         pair<int ,int>ans2 = helper(root->right);
        
         int height = ans1.second +  ans2.second + 1;
        
         pair<int ,int>ans;
        
         //maximum diameter
         ans.first =  max(height , max(ans1.first , ans2.first));
        
         //maximum height
         ans.second = 1 + max(ans1.second , ans2.second);
        
        return ans;
        
         
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
         if(root == NULL){
             return 0;
         }
        
         return helper(root).first-1;
    }
};