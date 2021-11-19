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
    
//if this is a leaf node then return 0 (means camera is not required)
//if this is parent of leaf node then return 1(then camera is placed)
//if this node child is parent of leaf nodes return 2(means its already covered)    
    int camera = 0;
    int helper(TreeNode* root){
           
        if(root == NULL){
            return 2;
            //means its already covered
        }
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        if(l == 0 || r == 0){
            camera++;
            return 1;
        }
        
        return (l == 1 || r == 1)?2:0;

    }
    int minCameraCover(TreeNode* root) {
         //helper(root);
        return (helper(root) < 1 ? 1 : 0) + camera;
    }
};