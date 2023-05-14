/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
void bsort(vector<int> &a, int size){
    if(size ==0 || size == 1)
        return ;
    for(int j=0;j<size-1;j++)
    {
        if(a[j] > a[j+1])
        {
            swap(a[j], a[j+1]);
        }
    }
    bsort(a, size-1);
    
}
int main()
{
    vector<int> a = {1,5,6,2,9,7};
    bsort(a,a.size());
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<"  ";
    return 0;
}
