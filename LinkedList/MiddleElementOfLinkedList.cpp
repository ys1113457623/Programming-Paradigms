https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=1&category%5B%5D=Linked%20List&curated%5B%5D=1&sortBy=submissions

class Solution{
    public:
    int reverseLinkedList(Node *head){
        Node *slow = head , *fast = haed;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
}