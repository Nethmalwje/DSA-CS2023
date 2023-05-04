#include <iostream>
using namespace std;
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   //heapify
    int maximum = root; // Initialize max root
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    // Check if a left child is present and if it is larger than the root
    if (l < n && arr[l] > arr[maximum])
        maximum = l;

    // Check if a right child is present and if it is larger than the root
    if (r < n && arr[r] > arr[maximum])
        maximum = r;

    // If largest is not root, swap the root with the larger child
    if (maximum != root) {
        swap(arr[root], arr[maximum]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, maximum);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call the heapify function 
        heapify(arr, i, 0);
    }
}

//printing the  contents of array //
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
