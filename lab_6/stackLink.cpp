#include <iostream>
using namespace std;

//Structure of the Node
struct Node
{
int data;

struct Node *link;
};

// top pointer to keep track of the top of the stack
struct Node *top = NULL;

void pushLinked(int x ){     //implementing push function for linked lists
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));  //using dynamaic memory allocation to create new nodes
    newnode -> data = x;
    newnode -> link = top;
    top = newnode;

}
void displayLinked(){
    struct Node*temp;   //tempary variale to containg top memory location
    temp = top;
    if (top == NULL){
        cout<<"stack  with linked lists is empty \n";
    }
    else{
        while(temp != NULL){      //printing out the strack
            cout<< temp->data<<" ";
            temp = temp -> link;
        }
        cout<< endl;
    }
}
void peek(){      // function to display the top element
    if (top == NULL){
        cout<<"stack  with linked lists is empty \n";
        }
    else{
        cout<<"top elemnt is: "<<top -> data << endl;
        }
    }
void popLinked(){       //creatin the function to pop the top item
    struct Node*temp;
    temp = top;
    if ( top == NULL){
        cout<<"stack  with linked lists is empty \n";
    }
    else{
        cout<<"poped element is: "<< top -> data<<endl;
        top = temp -> link;   //assigning new top element
    }
  }

int main(){
     pushLinked(1);
    pushLinked(2);
    pushLinked(3);
    displayLinked();
     popLinked() ;
     popLinked() ;
     popLinked() ;
     popLinked() ;
     displayLinked();
     return 0;

}