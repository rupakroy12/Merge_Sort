//Merge sort implementation by Rupak Roy
//Time complexity = O(n log n) (all three cases) 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge_sort(int [], int, int);                              //function declarations
void merge(int [], int , int , int);

// Function merge_sort(array , beginning index, end index)
void merge_sort (int arr[], int low, int high)                  
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }    
}

// function merge(main array, beginning index, middle index, end index)
void merge(int arr[], int low, int mid, int high)
{   
    
    int temp1_size = mid-low+1;                 //temp1 array size
    
    int temp2_size = high - mid;               //temp2 array size 

    //copying values of left part to temp1
    int temp1[temp1_size];                     //temp1 array declared to store elements of left part, i.e from beginning index to middle index values.
    for (int i = 0; i < temp1_size; i++)
    {
        temp1[i] = arr[low+i];
    }

    //copying values of right part to temp2
    int temp2[temp2_size];                    //temp2 array declared to store elements of right part, i.e from middle+1th index to end index values.
    for (int i = 0 ; i < temp2_size; i++ )
    {
        temp2[i] = arr[mid + 1 + i];
    }
    

    int ptr1 = 0;                // iterator for temp1 array
    int ptr2 = 0;               //  iterator for temp2 array
    int ptr3 = low ;           //   iterator for temp3 array
  
    
    while (ptr3 <= high)
    {   
        if (ptr1 < temp1_size && ptr2 < temp2_size)             // both temp1 and temp2 has values to copy
        {
            if (temp1[ptr1] < temp2[ptr2] )
                arr[ptr3++] = temp1[ptr1++];
            else 
                arr[ptr3++] = temp2[ptr2++];
        }
        
        else if (ptr1 > temp1_size-1 )                         // if ptr1 reached end of temp1, i.e no elements left for checking in temp1
            //copying remaining elements of temp2 to the main array
            arr[ptr3++] = temp2[ptr2++];

        else                                                   // if ptr2 reached end of temp2, i.e no elements left for checking in temp2
            //copying remaining elements of temp1 to the main array
            arr[ptr3++] = temp1[ptr1++];                       

    }
}

int main()
{
    int n;
    cout << "Enter array size : ";
    cin>>n;                                  // taking input of range of array

    int arr[n];

    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n-1);                //function call

    cout << "The sorted array is  : " ;
    for(int i = 0; i<n ; i++)
    {
        cout << arr[i] << " ";
    }

}