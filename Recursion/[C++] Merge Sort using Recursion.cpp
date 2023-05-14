#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int s, int mid, int e)
{
    //Firstly, create two subarrays and store values.
    int a_one_size = mid-s+1;
    int a_two_size = e-mid;
    int *left_array = new int[a_one_size];
    int *right_array = new int[a_two_size];
    
    for(int i=0;i<a_one_size;i++)
        left_array[i] = a[s+i];
    for(int i=0;i<a_two_size;i++)
        right_array[i] = a[mid+1+i];
    
    int index1, index2, main_index;
    index2 = index1 = 0;
    main_index = s;
    
    //Merge 2 Sorted Array.
    while(index1<a_one_size && index2<a_two_size)
    {
        if(left_array[index1] <= right_array[index2])
            a[main_index++] = left_array[index1++];
        else
            a[main_index++] = right_array[index2++];
    }
    
    while(index1<a_one_size)
    {
        a[main_index++] = left_array[index1++];
    }
    while(index2<a_two_size)
    {
        a[main_index++] = right_array[index2++];
    }
    
    delete []left_array;
    delete []right_array;
    
}
void mergesort(vector<int> &a, int s,int e){
    if(s>=e)
    {
        return;
    }
    int mid = s+(e-s)/2;
    mergesort(a, s, mid);
    mergesort(a, mid+1, e);
    merge(a, s, mid, e);
}
int main()
{
    vector<int> a= {11,22,55,1,6,9,5,99,101};
    mergesort(a, 0, a.size()-1);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    return 0;
}
