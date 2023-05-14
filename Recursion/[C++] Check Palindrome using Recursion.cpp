#include <iostream>

using namespace std;
bool palin(string &a,int i=0){
    if(i>(a.length()/2))
        return true;
    if(a[i] != a[a.length()-1-i])
        return false;
    return palin(a, i+1);
}
int main()
{
    string a="kishan";
    cout<<palin(a);
    return 0;
}
