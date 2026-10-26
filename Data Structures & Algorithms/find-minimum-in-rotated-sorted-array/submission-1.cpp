class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] < nums[right])       // vinduet er sorteret
            {
                return nums[left];
            }

            int mid = (left + right) / 2;  // regnes ud forfra hver runde

            if (nums[mid] >= nums[left])  // mid er i første stykke bruddet er til højre
            {
                left++;
                mid--;
            }
            else     // mid er i andet stykke: mindste er mid eller til venstre
            {
                right--;
                mid++;
            }
        }

        return nums[left];
    }
};
