#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;


#define max_capasity 1000     //maximum size of  the stack
class stack {
private:
    int top;                 // Index of top element
    int arr[max_capasity];       // Array to store elements
public:
    stack() {
        top = -1;         
    }

    void pushArr(int x){               //fucktion for push operation
        if (top == max_capasity -1){
            cout<<"stack overflow \n";
        }
        else{
            top++;
            arr [top]=x;
            
        }
    }
    void popArr(){           //function for push operation
        int item;
        if (top == -1){
            cout<<"stack underflow \n";
        }
        else{
            item=arr[top];
            top--;
            cout<<"poped item: "<< item<<endl;
        }
    }
    void peekArr(){                   //peek function for the stack
        if (top == -1){
            cout<<"stack underflow  \n";
        }
        else{cout<< arr[top];
        }
    }
    void displayArr(){           //function for the displaying the stack
        if(top<0){
            cout<<"stack is empty \n";
        }
        else{
            for (int i = top;i>=0;i--){
                 cout<<arr[i]<<" ";
             }
        cout<<endl;
        }
    }
};


//Structure of the Node
struct Node
{
int data;

struct Node *link;
};
class linked_list {
private:
    Node *top;
public:
    linked_list() {
        top = NULL;
    }

// top pointer to keep track of the top of the stack
///struct Node *top = NULL;

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
};

int main(){



//generate random numbers and put it onto a array to run the functions in the stacks


int push_data_arr[100];
    for (int i=0;i<99;i++){
        push_data_arr[i]=rand()%101;
    }        

cout<<"using array"<<endl;  //start functions using array stack

auto start = std::chrono::high_resolution_clock::now();


    stack stck1;
    for (int j = 0; j < 10; j++) {                    //doin push pop and display functions with random numbers for the array stack
        stck1.pushArr(push_data_arr[j]);
    }
    stck1.displayArr();
    for (int j = 0; j < 5; j++) {
        stck1.popArr();
    }
    stck1.displayArr();
    for (int j = 0; j < 20; j++) {
        stck1.pushArr(push_data_arr[j]);
    }
    stck1.displayArr();
    for (int j = 0; j < 3; j++) {
        stck1.popArr();
    }
    stck1.displayArr();

 auto end = std::chrono::high_resolution_clock::now();
    
 std::chrono::duration<double> elapsed = end - start;
 std::cout << " time taken using array implementation: " << elapsed.count() << " seconds" << std::endl;
cout<<endl;
cout<<endl;
   



cout<<"using linked list"<<endl;  //start functions using linked list stack


linked_list lstck1;
//measure the time taken by the linked list implementation of stack in nanoseconds

auto start_link = std::chrono::high_resolution_clock::now();

for (int j = 0; j < 10; j++) {
            lstck1.pushLinked(push_data_arr[j]);      //doing push pop and display functions randommly for the linked list stack
        }
lstck1.displayLinked();
for (int j = 0; j < 5; j++) {
            lstck1.popLinked();
        }
lstck1.displayLinked();
for (int j = 0; j < 20; j++) {
            lstck1.pushLinked(push_data_arr[j]);
        }
lstck1.displayLinked();
for (int j = 0; j < 3; j++) {
            lstck1.popLinked();
        }
lstck1.displayLinked();
auto end_link = std::chrono::high_resolution_clock::now();
    
 std::chrono::duration<double> elapsed_link = end_link - start_link;
 std::cout << " time taken using linked list implementation: " << elapsed_link.count() << " seconds" << std::endl;

}




