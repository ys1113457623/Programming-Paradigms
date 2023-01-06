https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1?page=1&category%5B%5D=Linked%20List&curated%5B%5D=1&sortBy=submissions

class Solution{
    public:
    Node* reverseLinkedList(Node* head){
        Node* prev = NULL,*curr = head , *temp;

        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
}