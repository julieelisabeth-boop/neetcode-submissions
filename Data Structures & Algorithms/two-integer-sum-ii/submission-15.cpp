class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        

    int i=0;
    int j=numbers.size()-1;
    vector<int> facit;
        while(i<=j)
        {

    if (numbers[i]+numbers[j]==target)
        {
                facit.push_back(i+1);
                facit.push_back(j+1);
                return facit;
        }
    else if(numbers[i]+numbers[j]<target)
    {
        i++;
    }
    else 
    {
        j--;
    }
    }
    return facit;
}
};
