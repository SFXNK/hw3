#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void div(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head==NULL)
    return;
  div(head->next, smaller, larger, pivot);
  if(head->val<=pivot){
    head->next=smaller;
    smaller=head;
  }
  else{
    head->next=larger;
    larger=head;
  }
}


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  smaller=NULL;
  larger=NULL;
  return div(head,smaller,larger,pivot);
}
