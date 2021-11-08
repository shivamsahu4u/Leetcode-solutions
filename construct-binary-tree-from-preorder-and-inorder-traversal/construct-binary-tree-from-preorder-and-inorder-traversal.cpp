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
    
    TreeNode* helper(vector<int>& preorder ,int pi , int pl ,  vector<int>&inorder , int ii , int jl){
        
        if(pi > pl || ii > jl){
            return NULL;
        }
        
        int ro = preorder[pi];
        TreeNode*root = new TreeNode(ro);
        
        int index = -1;
        
        for(int i = ii ; i <= jl ; i++){
            
            if(inorder[i] == ro){
                index = i;
                break;
            }
        }
        
        if(index != -1){
              //rt   l   r
        // 3 9 20 15 7  preorder
        // l rt   r 
        // 9 3 15 20 7  inorder
            int pil = pi + 1; 
            int pir = pil + index - ii - 1 ;
            int pll = pir + 1;
            int plr = pl;
            int iil = ii;
            int iir = index - 1;
            int jll = index + 1;
            int jlr = jl;
            
            
            root->left = helper(preorder , pil , pir , inorder , iil , iir);
            root->right = helper(preorder , pll , plr , inorder , jll , jlr);
            
            return root;
        }
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        
        return helper(preorder , 0 , preorder.size() - 1 , inorder , 0 , inorder.size() - 1);
    }
};