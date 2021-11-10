/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
  bool isPath(ListNode* head , TreeNode*root){
      
       if(!head){
           return true;
       }
      
      if(!root){
          return false;
      }
      
       if(head->val == root->val){
           
           return isPath(head->next , root->left) || isPath(head->next , root->right);
       }
      
      return false;
  }  
  bool isSubPath(ListNode* head, TreeNode* root) {
    
       if(root == NULL){
           return false;
       }
      
     return isPath(head , root) || isSubPath(head , root->left) || isSubPath(head , root->right);
  }  
/*Problem ::
Your code returns true even though the path is not continuous in the tree, try this one:
[1,2,3] 
[1,null,9,null,2,null,9,null,3]
*/
   /* bool isSubPath(ListNode* head, TreeNode* root) {
         if(head == NULL){
            return true;
        }
        if(root == NULL){
            
            return false;
        }
        
       
        //if linkedlist element not match with tree element
        if(head->val != root->val){
            
            bool ans1 = isSubPath(head , root->left);
            bool ans2 = isSubPath(head , root->right);
            
            return ans1||ans2;
        }else{
            //if both elements matches
            bool ans1 = isSubPath(head->next , root->left);
            bool ans2 = isSubPath(head->next , root->right);
            
            return ans1||ans2;
        }
        
    }*/
};