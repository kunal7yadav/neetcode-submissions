class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*tempA = head;
        ListNode*tempB ;
        ListNode*c = new ListNode(100);
        ListNode*tempC = c;
        while(tempA!=NULL && tempA->next!=NULL){
            tempB=tempA->next;
            ListNode * nextPair = tempB->next;
            tempC->next = tempB;
            tempB->next = tempA;
            tempA->next = nextPair;

           
            tempC= tempA;
            tempA = nextPair;
           

        }
        return c->next;   
    }
};