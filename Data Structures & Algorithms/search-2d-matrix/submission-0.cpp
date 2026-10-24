class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // antal rækker
        int n = matrix[0].size();     // antal kolonner

        // find rækken
        int top = 0; //toppen af matixen
        int bottom = m - 1;
        int row = -1;                 // -1 = ingen række fundet endnu

    // her forsøger vi at halvere selve matrixen
        while (top <= bottom)
        {
            int mid = (top + bottom) / 2;

            if (target < matrix[mid][0])            // target er mindre end hele rækken
            {
                bottom=mid-1; //den nye bund af maitrxen er midten -1
            }
            else if (target > matrix[mid][n - 1])   // target er større end hele rækken
            {
                top=mid+1; //den nye top er midten og så en række mere under
            }
            else                                    // target kan ligge i denne række
            {
                row = mid;
                break;
            }
        }

        if (row == -1)
        {
            return false;
        }

        // TRIN 2: halvér inde i rækken
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (target == matrix[row][mid])
            {
                return true;
            }
            else if (target < matrix[row][mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        return false;
    }
};