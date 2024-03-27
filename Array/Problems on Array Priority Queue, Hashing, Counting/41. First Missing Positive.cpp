// LeetCode -> 41. First Missing Positive
https://leetcode.com/problems/first-missing-positive/description/

// Similar Questions 
// (I) LeetCode -> 442. Find All Duplicates in an Array
       https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// (II)


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // patern -> Using number as the index
        
        // Intution -> The array size is n and you are only concering about to the [1, n] numbers
        // bcz you know that your answer is lies in between [1, n] then in that types of questions 
        // kuch esa kro ki taki array ki index ko numbers ki form m represent kr paye so that jb next 
        // time m array pr travers kre to direct index se pta kr paye ki number array m persent h ya nhi 
        // that means we optimised the searching in the array from T.C. = O(n) & S.C. = O(n) to 
        // T.C. = O(n) & S.C. = O(1)
        // Corner Case -> (i) What you should do with numbers who are <= 0 and > n
        //                 => if num <=0 && nums > n then convert it into 1 i.e nums[i] = 1
        //                (ii) What if one is already persent in array
        //                 => Check if 1 is persent or not if not then return 1 directly
        // After handling the corner cases just traverse the nums array and do this 
        // num = nums[i]
        // idx = nums - 1 
        // if(nums[idx] > 0) then nums[idx] *= -1 ; -> conver it into negative 
        // in the second for loop if you encounter the any index value which is not negative i.e. 
        // idx + 1 number is not persent in the nums array then return it 

        // e.g. -> [3, 4, -1, -2, 1, 5, 16, 0, 2, 0]  n = 10
        // first pass checking for is nums array contain 1 or not and num <= 0 && num > n and conert them into 1 
        // [3, 4, 1, 1, 1, 5, 1, 1, 2, 1]
        // now nums array have only [1, n] numbers then use number as index
        //  [-3, -4, -1, -1, -1, 5, 1, 1, 2, 1]
        // now you can see that 5 is not negative which is on idx 5 i.e 5+1 is not persent in nums array

        int n = nums.size() ;
        int containOne = false ;

        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1){
                containOne = true ;
            }
            if(nums[i] <=0 || nums[i] > n){
                nums[i] = 1 ;
            }
        }

        if(!containOne) return 1 ;

        for(int i=0 ; i<n ; i++){
            int num = abs(nums[i]) ;
            int idx = num - 1 ;
            if(nums[idx] > 0){
                nums[idx] *= -1 ;
            }
        }

        for(int i=0 ; i<n ; i++){
            if(nums[i] > 0)
                return i+1 ;
        }

        return n+1 ;

// -----------------------------------------------------------------------------------------------------------

        /*

        // Intution -> [1, n] tk ke numbers ko unki correct position pr dal do the mean of correct
        // position is that ki index 1 have value 1, index 2 have value 2, index 3 have value 3 and
        // so on. In the second pass or second traversing the array check is the index contain the correct
        // positioned number or not if not then that index is your answer.
        // the firstMissingPositive number will be in the range of [1, n] bcz the size of the array is
        // n and if array have all the positive number from [1, n] then your answer is n+1

        // The benifit of the this approch is that you are not changing the values of the nums array 
        // while you are only changing the position of the values 
        
        // T.C. = O(2n + n)
        // S.C. = O(1)
        int n = nums.size() ;
        nums.push_back(-1) ;
        int i=0 ;

        // T.C. = O(2n)
        // numbers ko unki correct positio pr dlna based on index
        // nums.push_back(-1)  this is bcz if number is equal to n then it should be inserted at nth positioned
        // nums[i] >=0 && nums[i] <= n number should be in between [0, n] 
        // nums[i] != i phle se correct position pr na ho
        // nums[i] != nums[nums[i]] to avoid the duplication of numbers
        while(i <= n){
            if(nums[i] >=0 && nums[i] <= n && nums[i] != i && nums[i] != nums[nums[i]]){
                swap(nums[i] , nums[nums[i]]) ;
            }
            else{
                i++ ;
            }
        }

        // T.C. = O(n)
        for(int j=1 ; j<=n ; j++){
            if(nums[j] != j)
                return j ;
        }

        return n+1 ;

        */

// --------------------------------------------------------------------------------------------------------------

        /*
        // intuition -> number ko set m store krva lo taki searching O(n) me ho jaye
        // T.C. = O(n)
        // S.C. = O(n)

        int n = nums.size() ;
        unordered_set<int> st ;

        for(auto &it: nums){
            st.insert(it) ;
        }

        for(int i=1 ; i<=n ; i++){
            if(st.find(i) == st.end())
                return i ;
        }

        return -1 ;
        */
    }
};