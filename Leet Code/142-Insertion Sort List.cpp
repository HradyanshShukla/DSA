class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode* sorted_head=insertionSortList(head->next);
        if(head->val<=sorted_head->val){
            head->next=sorted_head;
            return head;
        } else{
            ListNode*current=sorted_head;
            ListNode* prev=nullptr;
            while(current&&head->val>current->val){
                prev=current;
                current=current->next;
            }
            if(prev){
                prev->next=head;
            }
            head->next=current;
            return sorted_head;
        }
        
    }
};
