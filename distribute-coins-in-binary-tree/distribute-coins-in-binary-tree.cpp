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
    
    int steps = 0;
    int helper(TreeNode* root , int &steps ){
         if(root == NULL){
             return 0;
         }
        
        //coins needed or remained after left and right calls
        int ans1 = helper(root->left , steps);
        int ans2 = helper(root->right , steps);
        steps = steps + abs(ans1) + abs(ans2);
        
        return (ans1 + ans2 + root->val - 1);
    }
    int distributeCoins(TreeNode* root) {
        
        int steps = 0;
        helper(root , steps);
        return steps;
    }
};