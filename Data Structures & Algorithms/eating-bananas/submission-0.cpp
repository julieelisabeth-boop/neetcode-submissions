class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());
        int facit = maxSpeed;

        while (minSpeed <= maxSpeed)
        {
            int mid = (minSpeed + maxSpeed) / 2;       // hastigheden vi prøver

            long long timer = 0;                       // nulstilles hver runde
            for (int i = 0; i < piles.size(); i++)
            {
                timer += (piles[i] + mid - 1) / mid;   // timer for denne bunke, rundet op
            }

            if (timer <= h)
            {
                facit = mid;                           // hurtig nok: gem hastigheden
                maxSpeed = mid - 1;                    // prøv en mindre
            }
            else
            {
                minSpeed = mid + 1;                    // for langsom: prøv en større
            }
        }

        return facit;
    }
};