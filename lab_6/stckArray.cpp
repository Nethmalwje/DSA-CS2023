# include<iostream>
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

    void push(int x){               //function for push operation
        if (top == max_capasity -1){
            cout<<"stack overflow \n";
        }
        else{
            top++;
            arr [top]=x;
            
        }
    }
    void pop(){           //function for push operation
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
    void peek(){                   //peek function for the stack
        if (top == -1){
            cout<<"stack underflow  \n";
        }
        else{cout<< arr[top];
        }
    }
    void display(){           //function for the displaying the stack
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
int main() {
    stack s;
    s.push(45);
    s.push(34);
    s.push(23);
    s.push(46);
    s.push(12);
    s.push(78);
    s.push(93);
    s.push(58);
    s.push(64);
    s.push(21); 
    s.display();  
    s.pop();
    s.pop() ;
    s.pop() ;
    s.pop() ;
    s.pop() ;
    s.display();
    s.push(54);
    s.push(34);
    s.push(16);
    s.push(3); 
    s.display();
    return 0;
}




