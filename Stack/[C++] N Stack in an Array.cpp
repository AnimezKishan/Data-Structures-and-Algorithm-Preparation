/*

top -> it points to top element of each stack
next -> Before push, it points to next free space 
        After push, it points to next elements of the current stack
freespot -> to store a freespot of array.

T.C -> O(1)
S.C -> O(2s+n) -> O(s+n)

*/
#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n , s;

    int freespot;


public:
    // Initialize your data structure.
    //N = no. of stacks
    //S = size of array
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //initialise top
        for(int i=0;i<n;i++)
        {
            top[i] = -1;
        }

        //initialise next
        for(int i=0;i<s;i++)
        {
            next[i] = i+1;
        }
        //update last index to -1
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    //x -> element to push
    //m -> stack no.
    bool push(int x, int m)
    {
        
        if(freespot == -1)
            return false;

        int index = freespot;
        //update freespot
        freespot = next[index];

        //insert element
        arr[index] = x;

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};