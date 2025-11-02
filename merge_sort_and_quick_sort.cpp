/**
* Merge Sort and Quick Sort
* Author: Imtiaz Adar
*/

#include<bits/stdc++.h>
using namespace std;
// O(nlogn)
void merge_sort_process(vector<int>& nums, int left, int right, int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = nums[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = nums[mid + 1 + j];
    }
    int inx1 = 0, inx2 = 0, temp = left;
    while(inx1 < n1 && inx2 < n2){
        if(L[inx1] <= R[inx2]){
            nums[temp++] = L[inx1++];
        }
        else{
            nums[temp++] = R[inx2++];
        }
    }
    while(inx1 < n1){
        nums[temp++] = L[inx1++];
    }
    while(inx2 < n2){
        nums[temp++] = R[inx2++];
    }
}
void mergeSort(vector<int>& nums, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge_sort_process(nums, left, right, mid);
    }
}
// O(n^2)
int partition(vector<int>& nums, int low, int high){
    int pivot = nums[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(nums[j] <= pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}
void quickSort(vector<int>& nums, int low, int high){
    if(low < high){
        int pi = partition(nums, low, high);
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}
void display_(vector<int>& nums){
    for(auto it: nums){
        cout << it << " ";
    }
    cout << endl;
}
int main(){
    vector<int> numbers = {12, 5, 2, 7, 9, 11, 80, 70, 90, 50};
    int n = numbers.size();
    cout << "Merge Sort" << endl;
    mergeSort(numbers, 0, n - 1);
    display_(numbers);
    cout << "Quick Sort" << endl;
    quickSort(numbers, 0, n - 1);
    display_(numbers);
    return 0;
}
