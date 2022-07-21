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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        if(left == right){
            return head;
        }
        
        left = min(left , right);
        right = max(left , right);
         ListNode*temp1 = head ,*temp3 = NULL, *temp2 = head;
         
         while(left > 1){
             
             if(temp3 == NULL){
                 temp3 = head;
             }else{
                 temp3 = temp3->next;
             }
             temp1 = temp1->next;
             left--;
         }
        
         while(right > 1){
             temp2 = temp2->next;
             right--;
         }
        
        ListNode*temp4 = temp2->next;
        
        
        // head = temp1   , tail = temp2
          
        ListNode*t1 = NULL;
        ListNode*t2 = temp1;
        
        
        while(t2 != temp4){
            ListNode*d = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = d;
        }
        
        temp1->next = temp4;
        
        if(temp3 != NULL)
        temp3->next = t1;
        else{
            return t1;
        }
        
        return head;
        
        
    }
};