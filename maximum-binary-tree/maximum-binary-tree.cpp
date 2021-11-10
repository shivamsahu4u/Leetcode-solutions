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
    
    //Time Complexity -- O(n)(traverse in loop) + O(n)(iteration in stack)
    //now total time complexity will be O(n) only because in worst case while loop will run for n times only once 
    
    //Why time complexity is O(n)? Since we know that we are pusing and poping each node only once in/from vector , so if we have added all nodes in vector and taking out all the nodes in full span of iteration ,  we come out finally by removing O(n) elements only .
    
    //So total time complexity will be O(n) for iteration and O(n) for adding or removing elements from vector
     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      
            vector<TreeNode*>ans;
         
          for(int i = 0 ; i < nums.size() ; i++){
              
              TreeNode* curr = new TreeNode(nums[i]);
              
              while(ans.size() && ans.back()->val < nums[i]){
                 curr->left = ans.back();
                 ans.pop_back();
              }
              
              if(!ans.empty()){
                  ans.back()->right = curr;
               
              }
                 ans.push_back(curr);
          }
         
         return ans.front();
     }
    
    //time complexity -- O(n^2) 
    //Space complexity -- O(n) (recursive stack memory)
   /* TreeNode* helper(vector<int>&nums , int i , int j){
        
         if(i > j){
             return NULL;
         }
        
        int index = i, m = nums[i] , k;
        
        //finding maximum everytime takes O(n)
        for(k = i+1 ; k <= j ; k++){

            if(m < nums[k]){
                m = nums[k];
                index = k;
                
            }
        }
       
        TreeNode*root = new TreeNode(m);
    
        root->left = helper(nums , i , index-1);
        
        root->right = helper(nums , index+1 , j);
        
        return root;   
      
             
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
          return helper(nums , 0 , nums.size()-1);
    }*/
};
