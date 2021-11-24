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

    int len(ListNode* node){
        if(node == NULL) return 0;
        return 1 + len(node->next);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
         if(head == NULL){
            return NULL;
         }
        
        if(head->next == NULL){
            TreeNode*root = new TreeNode(head->val);
            return root;
        }
      
         int l = len(head);
        // l = (l%2==0) ? (l/2 - 1) : l/2;
      cout<<l<<endl;  
        ListNode*temp = head , *n = NULL , *pre = NULL;
        
        int i = 0;
        while(i < l/2){
            pre = temp;
            temp = temp->next;
            i++;
        }
 
        n = temp->next;
        TreeNode*root = new TreeNode(temp->val);
        // temp->next = NULL;
        
        if(pre != NULL)
        pre->next = NULL;
        
        root->left  = sortedListToBST(head);
        root->right = sortedListToBST(n);
        
        return root;
    }
};