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
    
    // Saf Suthra Solution
    int ans;
    void DFS(TreeNode* current , TreeNode* parent , TreeNode* grand){
        
         if(current == NULL){
             return;
         }
        
        if(grand != NULL && grand->val % 2 == 0){
            ans = ans + current->val;
        }
        
        DFS(current->left , current , parent);
        DFS(current->right , current , parent);
        
        
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        
         DFS(root , NULL , NULL);
        return ans;
    }
};


/*
 //O(n) - Time O(n) - sPACE
    int count = 0;
    void helper(TreeNode* root){
        
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            return ;
        }
        
        if(root->val % 2 == 0){
            
            if(root->left!= NULL && root->left->left != NULL){
                count = count + root->left->left->val;
            }
            
            if(root->left != NULL && root->left->right != NULL){
                count = count + root->left->right->val;
            }
            
            if(root->right != NULL){
                
                if(root->right->left != NULL){
                    count = count + root->right->left->val;
                }
                
                if(root->right->right != NULL){
                    count = count + root->right->right->val;
                }
            }
        }
        
        helper(root->left);
        helper(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        helper(root);
        
        return count;
    }
*/