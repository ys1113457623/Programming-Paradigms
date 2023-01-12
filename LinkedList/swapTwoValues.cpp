

 //MY SOLUTION
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }

        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode* front = head;
        ListNode* back = head;
        int n = getLength(head);
        for(int i=0;i<n-k;i++){
            back = back->next;
        }

        int back_value = back->val;

        for(int i=0;i<k-1;i++){
            front = front->next;
        }

        int front_value = front->val;

        

        back->val = front_value;
        front->val = back_value;


        return head;

    }
};

//OPTIMIZED SOLUTION
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size=0 ,  first_needed=0 , last_needed=0 ,tmpK=k ;
        ListNode * p =head ;

         // get size of list and the value in index k from first
        while(p!=NULL){
            size++;
            tmpK--;
            if(!tmpK) first_needed = p-> val ;
            p=p-> next ;
        }
        int idx= size- k + 1 ;   //the index of k from last 
        tmpK=0 , p=head; // update the value of tmpK , p to use  later


        // get the value of index k from last  
        while(p!=NULL){
            tmpK++;
            if(tmpK==idx){
                last_needed = p-> val ;
                break;
            }  
            p=p-> next ;
        }
        p=head;

         // swap two elements 
        while (p!=NULL){
                k--; idx--;
                if(!k) p-> val = last_needed;

                if(!idx) p-> val= first_needed;
                p=p-> next ;
        }

     return head;
    }
};


       
    