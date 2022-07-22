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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      
        vector<int>v;
        vector<int>s;
        ListNode*temp = head;
        
        while(temp !=NULL){
            if(temp->val < x)
            v.push_back(temp->val);
            else
            s.push_back(temp->val);
            
            temp=  temp->next;
        }
        
        temp = head;
        
        if(temp != NULL){
            int i = 0;
            while(i  < v.size()){
                temp->val = v[i];
                    i++;
                temp = temp->next;
            }
            i = 0;
            while(i < s.size()){
                temp->val = s[i];
                i++;
                temp = temp->next;
            }
            
        }
        
        return head;
        
        
    }
};