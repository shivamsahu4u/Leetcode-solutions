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
    
    TreeNode* helper(vector<int>&inorder , int ii , int ie , vector<int>&postorder , int pi , int pe){
        
         if(ii > ie || pi > pe){
             return NULL;
         }
        
        // 9 3 15 20 7 //inorder
        // 9 15 7 20 3 //postorder
        
        int r = postorder[pe];
        TreeNode*root = new TreeNode(r);
        
        int index = -1;
        
        for(int i = ii ; i <= ie ; i++){
            
            if(inorder[i] == r){
                index = i;
            }
        }
        
        if(index != -1){
         
             root->left = helper(inorder ,ii , index - 1 ,postorder , pi ,pi + index-ii-1);
             root->right = helper(inorder , index + 1 , ie , postorder , pi + index-ii , pe - 1);
             return root;
        }
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return helper(inorder , 0 , inorder.size()-1 , postorder,0 , postorder.size() - 1);
    }
};