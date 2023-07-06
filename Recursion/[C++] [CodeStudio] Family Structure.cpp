bool solve(long long int k)
{
	//base case (when reaches akash i.e. MALE)
	if(k == 1)
		return 1;
	
	//parent's gender = solve(k+1)/2;
	//if k is even, then it is opposite to its's parent gender
	if(!(k & 1))
		return 1-solve((k+1)/2);
	
	//if k is odd, then it is same as of it's parent.
	else
		return solve((k+1)/2);
}

string kthChildNthGeneration(int n, long long int k)
{
	if(solve(k))
		return "Male";
	
	else
		return "Female";
}