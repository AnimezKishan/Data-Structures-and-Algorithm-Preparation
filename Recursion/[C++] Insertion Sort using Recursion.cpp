#include <bits/stdc++.h>

using namespace std;
void insertionSort(vector<int> &a, int i){
    if(a.size() == 1 || i==a.size()-1)
        return;
    int j=i-1;
    int temp = a[i];
    while(j>=0)
    {
        if(a[j] > temp)
            a[j+1] = a[j];
        else
            break;
        j--;
    }
    a[j+1] = temp;
    insertionSort(a, i+1);
}
int main()
{
    vector<int> a= {10, 1, 7, 4, 8, 2, 11};
    cout<<"Before Sorting: \n";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<"  ";
    }
    insertionSort(a, 1);
    cout<<"\n\nAfter Sorting: \n";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<"  ";
    }
    return 0;
}
