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
    
    ListNode* merge(ListNode*head1 , ListNode*head2){
        
        ListNode*head = NULL;
        ListNode*tail = NULL;
        while(head1!=NULL && head2!=NULL){
            
            if(head1->val <= head2->val){
                if(head == NULL){
                  head = head1;
                  tail = head1;  
                }else{
                    
                  tail->next = head1;
                  tail = tail->next;
                }
                  ListNode*t = head1->next;
                  head1 = head1->next;
                 // if(t != NULL)
                 //  t->next = NULL;
                
            }else if(head1->val > head2->val){
                if(head == NULL){
                    head = head2;
                    tail = head2;
                }else{
                    
                    tail->next = head2;
                    tail =tail->next;
                }
                ListNode*t = head2->next;
                head2 = head2->next;
                //  if(t != NULL)
                // t->next = NULL;
            }
        }
        
        while(head1!=NULL){
            if(head == NULL){
                  head = head1;
                  tail = head1;  
                }else{
                    
                  tail->next = head1;
                  tail = tail->next;
                }
                  ListNode*t = head1->next;
                  head1 = head1->next;
             // if(t != NULL)
             //      t->next = NULL;
        }
        
        while(head2!=NULL){
             if(head == NULL){
                    head = head2;
                    tail = head2;
                }else{
                    
                    tail->next = head2;
                    tail =tail->next;
                }
                ListNode*t = head2->next;
                head2 = head2->next;
             // if(t != NULL)
             //    t->next = NULL;
            }
        
    tail->next = NULL;
      return head;
    }
    ListNode* sortList(ListNode* head) {
        
        //we can follow merge sort technique here
        
        //merge sort is break and combine
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        //FIND THE MID
        
        ListNode*slow = head;
        ListNode*fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode*mid = slow->next;
        slow->next = NULL;
        
        head = sortList(head);
        mid = sortList(mid);
        
        head = merge(head , mid);
        
        return head;
        
    }
};