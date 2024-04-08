// LeetCode -> 1700. Number of Students Unable to Eat Lunch
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int ones = 0; //count of students who prefer type1
        int zeros = 0; //count of students who prefer type0
		
        for(int stud : students){
            if(stud == 0) zeros++;
            else ones++;
        }
        
        // for each sandwich in sandwiches
        for(int sandwich : sandwiches){
            if(sandwich == 0){  // if sandwich is of type0
                if(zeros == 0){ // if no student want a type0 sandwich
                    return ones;
                }
                zeros--;
            }
            else{  // if sandwich is of type1
                if(ones == 0){  // if no student want a type1 sandwich 
                    return zeros;
                }
                ones--;
            }
        }
        return 0;
        


        // queue<int> q ;
        // for(auto it: students){
        //     q.push(it) ;
        // }

        // for(int i=0 ; i<sandwiches.size() ; i++){
        //     int size = q.size() ;
        //     int j = 1 ;
        //     while(!q.empty() && j <= size){
        //         if(sandwiches[i] == q.front()){
        //             q.pop() ;
        //             break ;
        //         }

        //         q.push(q.front()) ;
        //         q.pop() ;
        //         j++ ;
        //     }

        //     if(j > size){
        //         return q.size() ;
        //     }
        // }

        // return 0 ;
    }
};