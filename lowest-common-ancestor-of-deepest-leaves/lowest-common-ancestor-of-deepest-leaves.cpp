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
    
    int depth(TreeNode* root){
        
         if(root == NULL){
             return 0;
         }
        return 1 + max(depth(root->left) , depth(root->right));
    }
    
    TreeNode* helper(TreeNode*root , int s , int d){
        
         if(root == NULL){
             return NULL;
         }
        
        if(s == d){
            
           return root;
        }
        
        TreeNode*ans1 =  helper(root->left , s+ 1 , d) ;
      
      TreeNode* ans2 =  helper(root->right , s + 1 , d);
      
        if(ans1 != NULL && ans2 != NULL){
            return root;
        }
        
        if(ans1!= NULL){
           return ans1 ;
       }
        
        if(ans2 != NULL){
            return ans2;
        }
        
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      
         if(root == NULL){
             return root;
         }
        
        int d = depth(root);
        cout<<d<<endl;
        return helper(root , 1 , d);
    }
};