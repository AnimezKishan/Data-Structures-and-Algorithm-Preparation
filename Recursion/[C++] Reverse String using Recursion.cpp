#include <iostream>

using namespace std;
void rev(string &a, int s){
    if(s>(a.length()/2)){
        return;
    }
    swap(a[s], a[a.length()-s-1]);
    return rev(a, s+1);
}

int main()
{
    string a="abcde";
    rev(a,0);
    cout<<a;
    return 0;
}
