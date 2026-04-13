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
        int l = 1;
        int r = n;

        while (l <= r) {
            int midIdx = (l + r) / 2;
            if (guess(l) == 0) return l;
            else if (guess(r) == 0) return r;

            else if (guess(midIdx) == 1) l = midIdx + 1;
            else if (guess(midIdx) == -1) r = midIdx - 1;
            else if (guess(midIdx) == 0) return midIdx;
        }
    }
};