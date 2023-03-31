struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *current, *prev, *next;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
