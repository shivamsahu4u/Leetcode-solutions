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
   /* int ans = 0;
   void inorder(TreeNode* root,bool dir,int len){
        
        if(root==NULL) return ;
         
        ans=max(ans,len);
        if(dir==0){ //root is right
            inorder(root->left,1,len+1);//root will move to left
            inorder(root->right,0,1);
        }
        else{ //root is left
             inorder(root->right,0,len+1); // root will move to right
             inorder(root->left,1,1);
        }
         
        return ;
       } 
    
    int longestZigZag(TreeNode* root) {
        ans=0;
         inorder(root->left,1, 1); // root is left
         inorder(root->right,0, 1);// root is right
        
        return ans ;
    }*/
    
/*int ans;
void helper(TreeNode*root , bool s , int d){

    if(root == NULL) return;

    ans = max(ans , d);

    if(s == 0){
        helper(root->left , 1 , d+1);
        helper(root->right , 0 , 1);
    }else{
        //root is at right
        //means we need to move left
        helper(root->right , 0 , d+1);
        helper(root->left , 1 , 1);
    }
    return;
}
int longestZigZag(TreeNode*root){
  ans= 0;
   helper(root->left , 1 , 1); 
   //1 means root is at left
  
   helper(root->right , 0 , 1);
   //0 means root is at right 
    return ans;
}*/
    
 //Time Complexity -- O(n)
    //Space Compleity is -- O(height)
int ans = 0;
void helper(TreeNode*root , bool s , int d){

    if(root == NULL) return;

    ans = max(ans , d);

    if(s == 0){
        helper(root->left , 0 , 1);
        helper(root->right , 1 , d+1);
    }else{
        //root is at right
        //means we need to move left
        helper(root->left , 0 , d+1);
        helper(root->right , 1 , 1);
    }
    return;
}
int longestZigZag(TreeNode*root){

   helper(root->left , 0 , 1); 
   //0 means root is at left
   helper(root->right , 1 , 1);
   //1 means root is at right 
    return ans;
}
};