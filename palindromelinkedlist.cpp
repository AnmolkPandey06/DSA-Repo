//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


//link->  https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
    Node * reachmiddle(Node * head ){
         
        Node * slow=head;
        Node * fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
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
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head==NULL) return true;
        if (head->next==NULL) return true;
        
        
        
        ///get middle
        Node * middle=reachmiddle(head);
        
        //attaching the reverse
        Node *temp=middle->next;
        middle->next=reverser(temp);
        
        
        //step 3 compare the halves
        Node * start=head;
        Node *reversestart=middle->next;
        while(reversestart!=NULL){
            if(reversestart->data!=start->data){
                return false;
            }
            reversestart=reversestart->next;
            start=start->next;
        }
        
        
        ///again make the ll same as prev
        temp=middle->next;
        middle->next=reverser(temp);
        
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends