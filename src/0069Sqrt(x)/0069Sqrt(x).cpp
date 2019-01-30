class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1 ) return x;
        int l = 0, r = x;
        int mid, y;
        while(l <= r)
        {
            mid = (r - l) /2 + l;
            y = x / mid;
            if(y == mid )
                return y;
            else if(y < mid)
                r = mid - 1;
            if(y > mid)
            {
              if(l==r) return mid;
              l = mid + 1;  
            }

        }
        return y;
    }
};