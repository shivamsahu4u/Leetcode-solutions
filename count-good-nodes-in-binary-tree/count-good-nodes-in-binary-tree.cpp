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
    
    //good node : if from a path to that node, there are no node greater than that node
    
    int helper(TreeNode* root ,TreeNode* parent){
        if(root == NULL){
            return 0;
        }
        
         if(parent != NULL){
             
             if(parent->val < root->val){
                 parent = root;
             }
         }else{
             parent = root;
         }
        
        int ls = helper(root->left , parent);
        int rs = helper(root->right , parent);
        
        if(parent!=NULL){
            
            if(parent->val > root->val){
                return  ls+rs;
            }else{
                return 1 + ls+rs;
            }
        }else{
            return 1 + ls+rs;
        }
    }
    int goodNodes(TreeNode* root) {
        
        TreeNode*parent = NULL;
        return helper(root , parent);
    }
};