#include <bits/stdc++.h> 
void subseq(string &str, vector<string> &ans, string output, int i){
	if(i >= str.length())
	{
		if(!output.empty())
		{
			ans.push_back(output);
		}
		return;
	}
	//exclude
	subseq(str, ans, output, i+1);

	//include
	char element = str[i];
	output.push_back(element);
	subseq(str, ans, output, i+1);
}
vector<string> subsequences(string str){
	// Write your code here
	vector<string> ans;
	string output ="";
	int index=0;
	subseq(str, ans, output, index);
	return ans;
}
