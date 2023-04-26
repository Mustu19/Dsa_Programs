// Bubble sort and Selection sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
        }
    }
}

void selectionSort(int arr[] , int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n ; j++)
        {
            if(arr[j] < arr[i]){
                int temp = arr[j] ;
                arr[j] = arr[i] ;
                arr[i] = temp ;
            }
        }
    }
    
}
int main()
{
    int arr[] = {45 , 34 , 1 , 59 , 25 , 90 , 64} ;
    int n = sizeof(arr)/sizeof(arr[0]) ; 
    bubbleSort(arr , n);
    selectionSort(arr , n);
    cout<<"Sorted Array: " ;
    for (int i = 0; i < n ; i++)
    {
        cout<<arr[i]<<" " ;
    }   
    return 0;
}