int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;
    int maxFreq = 0;
    for(auto i:arr)
    {
        count[i]++;
        maxFreq = max(maxFreq, count[i]);
    }

    //Return the very first element which has maximum frequency
    for(auto i:arr)
    {
        if(maxFreq == count[i])
            return i;
    }
    return -1;
}