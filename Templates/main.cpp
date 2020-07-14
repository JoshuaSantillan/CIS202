/*
  Auhtor: Joshua Santillan
  Description: Using Templates
  Email: Joshuasantillan125821@student.vvc.edu
  Date of Creation: 3/27/2019
*/

#include<iostream>

template<typename T>
void swap(T& a,T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void selection_sort(T a[], int n)
{
    /* a[0] to a[n-1] is the array to sort */
    int i,j;
    
    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    int iMin;
    for (j = 0; j < n-1; j++)
    {
    /* find the min element in the unsorted a[j .. n-1] */
     
         /* assume the min is the first element */
         iMin = j;
         /* test against elements after j to find the smallest */
         for (i = j+1; i < n; i++)
         {
             /* if this element is less, then it is the new minimum */
             if (a[i] < a[iMin])
             {
                 /* found new minimum; remember its index */
                 iMin = i;
             }
         }
     
         if (iMin != j) 
         {
             swap(a[j], a[iMin]);
         }
     }
} 

template<typename T>
void print_array(T a[],int n)
{
    for(int i=0;i<n;i++)
       std::cout << a[i] << std::endl;
}

int main()
{
    
    int array[5] = {25,34,1,2,56};
    print_array(array,5);
    selection_sort(array,5);
    print_array(array,5);
    return 0;
}
