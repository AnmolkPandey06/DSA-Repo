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
class compare {
    public:
    bool operator ()(ListNode *a, ListNode * b){
        return a->val>b->val; 
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode *,vector<ListNode*> ,compare> pq;
        for(int i=0; i<lists.size(); i++){
            ListNode * temp=lists[i];
            if(temp!=NULL){
               pq.push(temp);
            }
            
        }
        ListNode * dummyhead=new ListNode(-1);
        ListNode * tail=dummyhead;
       while (!pq.empty()) {
    ListNode *temp = pq.top();
    pq.pop();
    if(temp!=NULL){
          tail->next = temp;
    tail = temp;
    if (temp->next != NULL) { // Check if temp has a valid next node
        pq.push(temp->next);
    }
    }
    
}
        return dummyhead->next;
    }
};