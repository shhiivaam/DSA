class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    if(head->next==NULL)
    {
        head=NULL;
        return head;
    }
    ListNode* temp=head;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    int mid=count/2;
    ListNode* ans=head;
    for(int i=1;i<mid;i++){
        ans=ans->next;
    }
    ans->next=ans->next->next;
    return head;
    }
};