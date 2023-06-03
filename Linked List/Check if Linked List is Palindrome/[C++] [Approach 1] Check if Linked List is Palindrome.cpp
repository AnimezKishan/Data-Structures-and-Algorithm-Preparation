#include<vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        /*
        -> create an array
        -> store values of LL in that array
        -> check for palindrome in that array
        */
        
        vector<int> ans;
        Node* temp = head;
        while(temp != NULL)
        {
            ans.push_back(temp->data);
            temp = temp->next;
        }
        
        for(int i=0;i<ans.size()/2;i++)
        {
            if(ans[i] != ans[ans.size()-1-i])
                return false;
        }
        return true;
    }
};
