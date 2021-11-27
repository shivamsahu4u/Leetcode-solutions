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
    
    TreeNode* helper(vector<int>&preorder , int s , int e){
        
        if(s > e){
            return NULL;
        }
        
        int index = -1;
        
        for(int i = s ; i <=e ; i++){
            
            if(preorder[s] < preorder[i]){
                index = i;
                break;
            }
        }
        
        TreeNode*root = new TreeNode(preorder[s]);
        
        if(index!=-1){
            
            root->left = helper(preorder , s+1 , index - 1);
            root->right = helper(preorder , index , e);
        }else{
            root->left = helper(preorder , s+1 , e);
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return helper(preorder , 0 , preorder.size() - 1);
    }
};