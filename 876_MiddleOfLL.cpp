class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        temp=head;
        count = count/2;
        while(count!=0){
            temp=temp->next;
            count--;
        }
        return temp;
    }
};
