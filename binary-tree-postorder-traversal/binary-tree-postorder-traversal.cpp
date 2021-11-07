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
    
    //Iterative solution
    //Using one stack
    //Time Complexity is O(n)
      vector<int> postorderTraversal(TreeNode* root) {
         
            vector<int>ans;
          if(root == NULL){
              return ans;
          }
          stack<TreeNode*>s;
          TreeNode*curr = root , *prev = NULL;
          
          while(curr != NULL || !s.empty()){
              
               if(curr!=NULL){
                   s.push(curr);
                   curr = curr->left;
               }else{
                   
                   curr = s.top();
                   if(curr->right == NULL || curr->right == prev){
                       cout<<curr->val<< " ";
                        ans.push_back(curr->val);
                        s.pop();
                        prev = curr;
                       curr = NULL;
                   }else{
                       curr = curr->right;
                   }
               }
          }
          
          return ans;
        }
    
    //Iterative Solution
    //Using two stack
  /*   vector<int> postorderTraversal(TreeNode* root) {
         vector<int>ans;
         if(root == NULL){
             return ans;
         }
       
            stack<TreeNode*>s;
            stack<TreeNode*>p;
         s.push(root);
         while(s.size()!= 0){
             
              TreeNode* top = s.top();
              s.pop();
              if(top->left != NULL)s.push(top->left);
              if(top->right !=NULL )s.push(top->right);
             
              p.push(top);
         }
         
         while(p.size() != 0){
             
              ans.push_back(p.top()->val);
             p.pop();
         }
         
         return ans;
     }      */   
         
    //Recursive Solution
    // Time - O(n)
    // Space - O(n)(Recursive Stack Call)
   /* void helper(TreeNode* root , vector<int>&v){
        
        if(root == NULL){
            return;
        }
        
        helper(root->left , v);
        helper(root->right , v);
        
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
          
          vector<int>v;
        
          helper(root , v);
        
        return v;
    }*/
};
