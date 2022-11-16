/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int ans=-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int found = guess(mid);
            if(found == 0)
            {
                ans=mid;
                break;
            }
            else if(found == -1) high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
};