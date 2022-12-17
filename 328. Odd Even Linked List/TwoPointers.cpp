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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd, *even, *o, *e;
        
        if(!head || !head->next) 
            return head;
         
        odd = head; 
        even = head->next; 

        // o,e are traversal pointers
        o = odd;
        e = even;
        
        while(e && e->next){
            o->next = o->next->next;
            e->next = e->next->next;

            o = o->next;
            e = e->next;
        }
        
        // Append even to odd
        o->next = even;
        return odd;
    }  
};