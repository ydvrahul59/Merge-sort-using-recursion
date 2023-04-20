#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    // mujhe 2 array create krne padenge,aur uske length hogi,len1&len2
    int len1 = mid - s + 1;
    int len2 = e-mid;

    // creating two dynamic arrays 
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }
    // copying valuse to 2nd half created array
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }
    // merging 2 sorted arrays, ye pura logic merge two sorted wala hai
    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    while(index1< len1 && index2 < len2){
        if(first[index1]< second[index2]){
            arr[mainArrayIndex++] = first[index1++];
            
        }else{
            arr[mainArrayIndex++] = second[index2++];
        }

    }
    /*iske baad airf first wle mein jynge ho skta hai ki kisi 
    ek ka length jyda ho dusre wale se, toh alg se check kr lenge*/

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e){

    // base case
    if(s>=e){
        return;
    }
    
    int mid = s + (e-s)/2;

    // left part sort karna hai
    mergeSort(arr, s, mid);

    // right part sort karna hai
    mergeSort(arr,mid+1,e);

    // merge
    merge(arr, s, e);
}

int main(){

    int arr[5] = { 2,5,1,6,9};
    int n = 5;
    mergeSort(arr, 0, n-1);
    // cout<<"hi"<<endl;

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }cout << endl;
 

} 

// Time complexity = 0(nlogn)
// space complexity = 0(n)