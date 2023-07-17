bool isPalindrome(ListNode* head) {
        ListNode *fast, *slow;
        fast=slow=head;
        if(fast->next==NULL) return true;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *curr,*prev,*next;
        curr=slow;
        prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        fast=head; slow=prev;
        while(slow){
            if(fast->val != slow->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
