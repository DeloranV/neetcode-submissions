class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        long l = 0;
        long r = x / 2;

        long midIdx = (l + r) / 2;
        while (l <= r) {
            midIdx = (l + r) / 2;

            if ((long)l * l == x) return l;
            else if ((long)r * r == x) return r;

            if ((long)midIdx * midIdx == x) return midIdx;
            else if ((long)midIdx * midIdx < x) l = midIdx + 1;
            else r = midIdx - 1;
        }
        if ((long)r * r < x) return r;
        else if ((long)midIdx * midIdx < x) return midIdx;
        else if ((long)l * l < x) return l;
        return l;
    }
};