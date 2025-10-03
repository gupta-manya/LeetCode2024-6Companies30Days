class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right)return head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev=dummy;
        for(int i =1 ; i< left ; i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        ListNode* up =NULL;
        ListNode* prevsub = NULL;
        for(int i =0 ; i<=right-left ; i++){
            up =curr->next;
            curr->next =prevsub;
            prevsub=curr;
            curr= up;
        }
        prev->next->next =curr;
        prev->next = prevsub;
        return dummy->next;
    }
};
