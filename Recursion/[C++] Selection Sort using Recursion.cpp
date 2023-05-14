

#include <bits/stdc++.h>

using namespace std;
void ssort(vector<int> &a, int i){
    if(i == a.size()-1)
        return ;
    int min = i;
    for(int j=i+1;j<a.size();j++)
    {
        if(a[j] < a[min])
            min = j;
    }
    swap(a[i], a[min]);
    ssort(a, i+1);
}
int main()
{
    vector<int> a={1,5,7,2,3,9,8};
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"  ";
    }
    ssort(a,0);
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"  ";
    }
    return 0;
}
