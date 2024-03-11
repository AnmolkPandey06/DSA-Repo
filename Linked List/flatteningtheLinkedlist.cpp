/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };

 */



Node * findmid(Node * head){
    Node * slow=head;
    Node * fast=head->child;

    while(fast!=NULL && fast->child!=NULL){
        slow=slow->child;
        fast=fast->child->child;
    }
    return slow;
}


//merge two  sorted linked list
Node * combiner(Node *left,Node * right){
     if(left==NULL) return right;
     if(right==NULL) return left;

     Node * ans= new Node(-1);
     Node * temp=ans;
     
     
     while(left!=NULL && right!=NULL ){
         if(left->data <right->data){
             temp->child=left;
             temp=left;
             left=left->child;
         } 
         else{
             temp->child=right;
             temp=right;
             right=right->child;
         }
     }
     while(left!=NULL){
        temp->child=left;
        temp=left;
        left=left->child; 
     }
     while(right!=NULL){
        temp->child=right;
        temp=right;
        right=right->child;
     }

     
     return ans->child;

}



Node* mergeSort(Node *head) {
    // Write your code here.
    //base case
    if(head==NULL|| head->child==NULL){
        return head;
    }

    //find the mid
    Node *mid=findmid(head);

    //Now left and right
    Node * left=head;
    Node * right =mid->child;
    mid->child=NULL;
     
     //recursive call to both
    left=mergeSort(left);
    right=mergeSort(right);

    //combining both 

    Node * combine= combiner(left,right);
      
    return combine;

}

Node* flattenLinkedList(Node* head) 
{
	//head'
	Node * p=head;
    
	while(p!=NULL){
		Node *childtrav=p;
		Node * temp=p->next;
		while(childtrav->child!=NULL){
			childtrav->next=NULL;
			childtrav=childtrav->child;
		}

        // merge(p,)  

		childtrav->child=temp;
		p=temp;
	}


	head=mergeSort(head);

     


	return head;

}
