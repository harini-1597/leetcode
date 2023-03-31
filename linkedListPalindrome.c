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
    int count;
    for(struct ListNode* cur=head; cur!=NULL; cur=cur->next){
        count++;
    }
    
    struct Stack* S = createStack(count);
    for(struct ListNode* sor=head; sor!=NULL; sor=sor->next){
        push(S, sor->val);
    }
    int flag;
    for(struct ListNode* ptr=head; ptr!=NULL; ptr=ptr->next){
        if(ptr->val==pop(S)){
            flag=1;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
}
