struct Stack{
    int top;
    int cap;
    int *array;
};

struct Stack *createStack(int cap){
    struct Stack *S = malloc(sizeof(struct Stack));
    S->cap = cap;
    S->top = -1;
    S->array = malloc(S->cap*sizeof(int));
    //dynamically allocate here too, not simple array declaration
    return S;
}

void push(struct Stack* S, int data){
    S->array[++S->top] = data;
}

int pop(struct Stack* S){
    return(S->array[S->top--]);
}

bool isPalindrome(struct ListNode* head){
    struct ListNode* cur = head;
    int count=0;
    while(cur!=NULL){
        count++;
        cur=cur->next;
    }
    cur=head; 
    
    struct Stack* S = createStack(count);
    while(cur!=NULL){
        push(S, cur->val);
        cur=cur->next;
    }
    cur=head;
    
    int flag;
    while(cur!=NULL){
        if(cur->val == pop(S)){
            flag=1;
        }
        else{
            flag=0;
            break;
        }
        cur=cur->next;
    }
    
    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
}
