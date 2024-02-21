https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        while(right > left){
            right = right & (right -1) ;
        }
        
        return right ;


        // if(left == right) return left ;

        // for(int i=0 ; i<=31 ; i++){
        //     int powerOf2 = (1 << i) ;
        //     if(left < powerOf2 && powerOf2 <= right){
        //         cout << powerOf2 ;
        //         return 0 ;
        //     }
        // }

        // long long int ans = left ;
        // long long int l = left ;
        // while(l <= right){
        //     ans = ans & l ;
        //     l++ ;
        // }

        // return ans ;
    }
};