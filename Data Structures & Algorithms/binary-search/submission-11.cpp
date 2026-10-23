class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left=0;
        int midt=nums.size()/2;
        int right=nums.size()-1;


    while (left<=right)
    {
        if (nums[midt]==target)
        {
            return midt;
        }
        else if (nums[midt]>target)
        {
            right=midt-1;
            midt=(left+right)/2;
        }
        else if (nums[midt]<target)
        {
            left=midt+1;
            midt=(left+right)/2;
        }
    
    }
       return -1; 
    }

};
