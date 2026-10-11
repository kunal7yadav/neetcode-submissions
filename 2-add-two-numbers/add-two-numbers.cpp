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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*tempL1 = l1;
        ListNode*tempL2 = l2; 
        ListNode*c = new ListNode(100);
        ListNode*tempL3 = c ;
        int extra = 0;
        while(tempL1!=NULL && tempL2!=NULL){
            int sum = extra + tempL1->val + tempL2->val ;
            ListNode* t = new ListNode(sum%10);
            extra = sum/10;
            tempL3->next = t;
            tempL3= t ;
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
        }
        
        if(tempL1==NULL){
            while(tempL2){
            int sum = extra + tempL2->val;
            ListNode* t = new ListNode(sum%10);
            extra = sum/10;
            tempL3->next = t;
            tempL3= t ;
            tempL2 = tempL2->next;
            }
        }
        else{
            while(tempL1){
            int sum = extra + tempL1->val ;
            ListNode* t = new ListNode(sum%10);
            extra = sum/10;
            tempL3->next = t;
            tempL3= t ;
            tempL1 = tempL1->next;
            }
        }
        if(extra>0){
            ListNode* t = new ListNode(extra);
            tempL3->next = t;
            tempL3= t ;
            }
        return c->next;  
    }
};