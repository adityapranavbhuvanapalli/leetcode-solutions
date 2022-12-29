class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *cur = nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;  // MinHeap
        for(auto list: lists) {
            while(list) {
                pq.push(list->val);
                list = list->next;
            }
        }

        // Add the elements from pq to head
        while(pq.size()) {
            int top = pq.top();
            pq.pop();
            if(!cur) {
                cur = new ListNode(top);
                head = cur;
            } else {
                cur->next = new ListNode(top);
                cur = cur->next;
            }
            
        }

        return head;
    }
};