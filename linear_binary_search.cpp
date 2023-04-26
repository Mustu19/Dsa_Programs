#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void linearSearch(int arr[] , int n ,int target){
    int flag = 0 , e ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == target){
            flag = 1 ;
            e = i ;
        }
    }
    if(flag){
        cout<<"\nELement found at index "<<e ;
    }
    else{
        cout<<"\nElement not found";
    }
}

void binarySearch(int arr[]  ,int n , int target){
    sort(arr , arr+n);
    int start = 0 ;
    int end = n -  1 ;
    int flag = 0  , e ;
    while(start<=end){

            int mid = start + (end - start)/2 ;

            if(target > arr[mid]){
                start = mid+1 ;
            }
            else if(target < arr[mid]){
                end = mid - 1 ;
            }
            else{
                e = mid ;
                flag = 1; 
                break;
            }
        }
    if(flag==1){
        cout<<"\nElement found at index "<<e;
    }else{
        cout<<"\nElement not found" ;
    } 
    
}
int main()
{
    int arr[] = {98 , 56 , 34 , 1 , 4 , 49 , 91} ;
    int target ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    cout<<"Enter the element you want to search : " ;
    cin>>target ;
    linearSearch(arr , n , target);
    binarySearch(arr , n  , target) ;
    return 0;
}