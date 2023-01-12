class Solution{
    public:
    Node *mergeList(Node *head1, Node *head2){
        Node *dummy = new Node(-1001);
        Node *head = dummy;

        if(head1==NULL) return head2;
        if(head2==NULL) return head1;

        while(head1!=NULL && head2!=NULL){
            if(head1->value < head2->value){
                Node *newNode = new Node(head1->value);
                dummy->next = newNode;
                head1 = head1->next;
            }
            else{
                Node *newNode = new Node(head2->value);
                dummy->next = newNode;
                head2 = head2->next;
            }

            dummy = dummy->next;
        }

        if(head1!=NULL) {
            dummy->next = head1;
        }
        if(head2!=NULL){
            dummy->next = head2;
        }
    }
}