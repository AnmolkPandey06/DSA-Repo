/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

//LINK->https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=SUBMISSION


node * findmid(node * head){
    node * slow=head;
    node * fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


//merge two  sorted linked list
node * combiner(node *left,node * right){
     if(left==NULL) return right;
     if(right==NULL) return left;

     node * ans= new node(-1);
     node * temp=ans;
     
     
     while(left!=NULL && right!=NULL ){
         if(left->data <right->data){
             temp->next=left;
             temp=left;
             left=left->next;
         } 
         else{
             temp->next=right;
             temp=right;
             right=right->next;
         }
     }
     while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next; 
     }
     while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
     }

     
     return ans->next;

}



node* mergeSort(node *head) {
    // Write your code here.
    //base case
    if(head==NULL|| head->next==NULL){
        return head;
    }

    //find the mid
    node *mid=findmid(head);

    //Now left and right
    node * left=head;
    node * right =mid->next;
    mid->next=NULL;
     
     //recursive call to both
    left=mergeSort(left);
    right=mergeSort(right);

    //combining both 

    node * combine= combiner(left,right);
      
    return combine;

}