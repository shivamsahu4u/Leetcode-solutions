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
    
     vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
         
         stack<TreeNode*>s1 , s2;
         vector<int>ans;
         TreeNode*temp1 = root1 , *temp2 = root2;
          while(temp1!=NULL){
              s1.push(temp1);
              temp1 = temp1->left;
          }
         while(temp2!=NULL){
             s2.push(temp2);
             temp2=temp2->left;
         }
         while(!s1.empty() || !s2.empty()){
             
             if(!s1.empty() && (s2.empty() || s1.top()->val < s2.top()->val)){
                 ans.push_back(s1.top()->val);
                 TreeNode*k = s1.top();
                 s1.pop();
                 
                 if(k->right!=NULL){
                     TreeNode*temp = k->right;
                     while(temp!=NULL){
                         s1.push(temp);
                         temp = temp->left;
                     }
                 }
             }else{
                 ans.push_back(s2.top()->val);
                 TreeNode*k = s2.top();
                 s2.pop();
                 
                 if(k->right!=NULL){
                     TreeNode*temp = k->right;
                     while(temp!=NULL){
                         s2.push(temp);
                         temp = temp->left;
                     }
                 }
             }
         }
         return ans;
     }
  /*  vector<int>ans , res;
    void helper(TreeNode* root){
        if(root == NULL) return ;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      
          helper(root1);   // O(no. of nodes say m)
          helper(root2); // O(no. of nodes say n)
        for(int i = 0 ; i < res.size() ; i++){
            ans.push_back(res[i]);
        }  // O(min(m,n))
        
       sort(ans.begin() , ans.end());  
      //we can use two pointer approach here  
        
        return ans;
    }*/
};