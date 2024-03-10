//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:


    Node * reverser(Node * head ){
        Node *prev=NULL;
        Node *curr=head;
        Node *next=head->next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
        
    }

    void insertAtTail(Node* &head,Node * &tail, int digit){
          
          if (head==NULL){
             Node * temp= new Node(digit);
             head=temp;
             tail=temp;
  
          }

          else{
             Node * temp= new Node(digit);
             tail->next=temp;
             tail=temp;  
          }
          

    }
   
    Node * add(Node *rf, Node * rs){
        int carry=0;
        Node * anshead=NULL;
        Node * anstail=NULL;
        while(rf!=NULL && rs!=NULL){
            int sum=carry+rf->data+rs->data;
            int digit=sum%10;
            insertAtTail(anshead,anstail,digit);
            carry=sum/10;
            rf=rf->next;
            rs=rs->next;
        } 
        while(rf!=NULL){
            int sum=carry+rf->data;
            int digit=sum%10;
            insertAtTail(anshead,anstail,digit);
            carry=sum/10;
            rf=rf->next;
            
        }
        while(rs!=NULL){
            int sum=carry+rs->data;
            int digit=sum%10;
            insertAtTail(anshead,anstail,digit);
            carry=sum/10;
            rs=rs->next;
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            insertAtTail(anshead,anstail,digit);
            carry=sum/10;
        }
        return anshead;
    }

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
         
        
        // reversing the linked lists
          Node * rf=reverser(first);
          Node * rs=reverser(second);

        // adding 
          Node *addhead=add(rf,rs);

        // return by reversing again
          return reverser(addhead);  
        
         return rf;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends