bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *tortoise=head, *hare=head;
        while(hare!=NULL && hare->next!=NULL){
            tortoise=tortoise->next;
            hare=hare->next->next;
            if(tortoise==hare)
                return true;
        }
        return false;
    }
