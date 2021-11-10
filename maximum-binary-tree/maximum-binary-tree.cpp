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
    
    TreeNode* helper(vector<int>&nums , int i , int j){
        
         if(i > j){
             return NULL;
         }
        
        int index = i, m = nums[i] , k;
        
        for(k = i+1 ; k <= j ; k++){
            // cout<<nums[k]<<" "<<k<<" ";
            if(m < nums[k]){
                m = nums[k];
                index = k;
                
            }
        }
        cout<<endl;
       TreeNode*root = new TreeNode(m);
        // cout<<m<<endl;
    
        root->left = helper(nums , i , index-1);
        
        root->right = helper(nums , index+1 , j);
        
        return root;   
      
             
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
          return helper(nums , 0 , nums.size()-1);
    }
};