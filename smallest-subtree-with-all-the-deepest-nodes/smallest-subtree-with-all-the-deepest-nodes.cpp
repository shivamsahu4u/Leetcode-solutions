
class Solution {
public:
     //Time Complexity is O(n)(helper function) + O(n) (depth calculation) = O(2n) = O(n)
    //Space Complexity is O(n) (recursive stack memory)
    int depth(TreeNode* root){
         if(root == NULL) return 0;
         return 1 + max(depth(root->left) , depth(root->right));
    }
    
    TreeNode* helper(TreeNode*root , int s , int d){
        
         if(root == NULL || s == d) return root;
       
        TreeNode*ans1 =  helper(root->left , s+ 1 , d) ;
        TreeNode* ans2 =  helper(root->right , s + 1 , d);
      
        if(ans1 != NULL && ans2 != NULL)return root;
        if(ans1!= NULL) return ans1 ; 
        if(ans2 != NULL)return ans2;
        return NULL;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      
         if(root == NULL) return root;
         int d = depth(root);
         return helper(root , 1 , d);
    }
};