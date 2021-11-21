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
        
    //Time Complexity is O(n2) skewed tree in worst case
    //Space complexity is O(h) h being the depest node of the tree
    int helper(TreeNode* root , int s){
        if(root == nullptr) return 0;
        int res = 0;
        if( s == root->val){
            res++;
        }
        res+=helper(root->left, s - root->val) + helper(root->right , s - root->val);
        return res;
    }
    //not includeing the root
    int pathSum(TreeNode* root, int targetSum) {
        
        /*
        1st case - include the root
        2nd case - disinclude the root
        */
        if(root == nullptr) return 0; 
        return pathSum(root->left , targetSum) + pathSum(root->right , targetSum) + helper(root , targetSum);
    }
    
    //Time complexity - O(n) 
    //Space complexity - O(n) (hashmap) + O(n) (skewwd tree) (recursion) 
    /*
    class Solution {
public:
    unordered_map<int, int> map;
    int count = 0;
    
    void countPathSum(TreeNode* root, int target, int sum){
        if(!root)
            return;
        sum += root->val;        //Path sum from root
        if(sum == target)
            count++;
        if(map.find(sum - target) != map.end())         //checking whether any target sum path present in the path from root to the current node
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;      //After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);
        return count;
    }
};
    */
};