#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s,int e){
    int cnt=0;
    int pivot = arr[s];
    //count the elements smaller than pivot 
    for(int i=s+1;i<arr.size();i++)
    {
        if(arr[i] < arr[s])
            cnt++;
    }
    //assign the pivot its correct place
    int pivotIndex = s+cnt;
    swap(arr[s], arr[pivotIndex]);
    int i=s, j=e;
    //Place smaller elements into left of pivot and greater into right.
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i] < arr[pivotIndex])
            i++;
        while(arr[j] > arr[pivotIndex])
            j--;
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
    
}
void quickSort(vector<int> &arr, int s,int e){
    if(s>=e)
        return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main()
{
    vector<int> a={20,50,40,100,70,10,30};
    int n=a.size()-1;
    quickSort(a, 0, n);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
