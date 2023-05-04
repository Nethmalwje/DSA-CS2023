#include <iostream>
using namespace std;
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   //heapify
    int maximum = root; // intitalze max root
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    
    if (l < n && arr[l] > arr[maximum]) // Check if a left child is present and if it is larger than the root
        maximum = l;

    
    if (r < n && arr[r] > arr[maximum]) // Check if a right child is present and if it is larger than the root
        maximum = r;

    // swap the root with the the larger child
    if (maximum != root) {
        swap(arr[root], arr[maximum]);

        // Recursvely heapify the sub-tree
        heapify(arr, n, maximum);
    }

}

// heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extracting elements  one by one
    for (int i = n - 1; i >= 0; i--) {
        
        swap(arr[0], arr[i]); // Move current root to the end

         
        heapify(arr, i, 0); // call the heapify function
    }
}

//printing the  contents of array 
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
  
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main function
int main()
{
    int arr_length =10 ;
    int heap_arr[arr_length] ;

   for(int i=0;i<arr_length;i++){
    heap_arr[i]=rand()%61;
   }

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
