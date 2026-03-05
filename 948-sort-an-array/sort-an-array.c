/*Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.*/
 

#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=m)
        temp[k++] = arr[i++];

    while(j<=r)
        temp[k++] = arr[j++];

    for(i=l, k=0; i<=r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){

    mergeSort(nums,0,numsSize-1);

    *returnSize = numsSize;

    return nums;
}