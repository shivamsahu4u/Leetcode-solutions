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
    
   int p = 0;
     TreeNode* helper(vector<int>& preorder  ,int s , int e ,unordered_map<int , int>&hash){
          
          if(s > e){
              return NULL;
          }
         
         TreeNode* root = new TreeNode(preorder[p]);
         p++;
         int index = hash[root->val];
         
         root->left = helper(preorder,  s , index - 1 , hash);
         root->right = helper(preorder ,  index +1 , e , hash);
         
         return root;
      
     }
    
    TreeNode* subhelper(vector<int>& preorder , vector<int>& inorder){
        
        //hashmap to indexes of the inorder traversal 
        unordered_map<int , int>hash;
        
        for(int i = 0 ; i < inorder.size();  i++){
            hash[inorder[i]] = i;
        }
        cout<<hash[-1]<<endl;
        return helper(preorder,0 , inorder.size() - 1 ,  hash);
    }
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
             
           return subhelper(preorder , inorder);
     }
    
/*    TreeNode* helper(vector<int>& preorder ,int pi , int pl ,  vector<int>&inorder , int ii , int jl){
        
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
    }*/
};