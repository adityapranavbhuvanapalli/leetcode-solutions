/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode *head=l1, *prev, *new;
    while(l1!=NULL && l2!=NULL) {
        l1->val+=(l2->val+carry);
        if(l1->val>9) {
            l1->val-=10;
            carry=1;
        } else {
            carry=0;
        }
        prev=l1;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        l1->val+=carry;
        if(l1->val>9) {
            l1->val-=10;
            carry=1;
        } else {
            carry=0;
        }
        prev=l1;
        l1=l1->next;
    }
    prev->next=l2;
    l1=l2;
    while(l1!=NULL){
        l1->val+=carry;
        if(l1->val>9) {
            l1->val-=10;
            carry=1;
        } else {
            carry=0;
        }
        prev=l1;
        l1=l1->next;
    }
    
    if(carry==1) {
        new = (struct ListNode*) malloc(sizeof(struct ListNode));
        new->val=carry;
        new->next=NULL;
        prev->next=new;
    }
    
    return head;
}