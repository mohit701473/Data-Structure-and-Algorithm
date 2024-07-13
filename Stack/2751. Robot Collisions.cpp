// LeetCode -> 2751. Robot Collisions

/*
location -> Data-Structure-and-Algorithm/Stack/2751. Robot Collisions.cpp

Approch -> Sorting + Stack

Intution: sort the position vector bcz take an example positions = [5,1,3,2] so when u do
          processing then u pick first pos = 5 and then u pick pos = 1 and check is they collide
          but it might be possible that some other robots are persent in between these two positions
          so if we sort the positions then we sort this type of problem is not occur

          now check when the collosion occur between two robots
          any robot can move in two direction right(R) or left(L) so if we check for collosion then 
          we have to check for two robots i.e there are four combination availabe
          first robot    &    second robot
               R                  R
               R                  L
               L                  R
               L                  L
          first robot's position < second robot's position then (R, R), (L, L) and (L, R) moving 
          directions will never collide bcz (R,R) and (L, L) moving in same direction & (L, R) means
          <-- L & R --> both moving in opposite direction so no collision

          now if there is case where first robot moving in right(R) and second robot moving in left(L)
          then there can be collosion occur i.e. start traversing the positions array from i = 1 and
          if robot's directionis left(L) then check the previous robots's (i-1) direction if that is 
          right(R) then collosion occur then u have to remove based on based on the health and 
          suppose while traversing the positions array u we get R,R,R,R i.e. first four robot's moving
          in right directio then when next robot is moving in left(L) direction then u have to process
          last robot and this robot i.e. u process last inserted robot and if it's health is less then
          this new robot's health then u have to remove or pop that last inserted robot.
          It is like u doing last in first out i.e LIFO so u can think of stack data structure.

          Now as we seen that first sorting of positions vector is required and with sorting rember the
          previous indexing because based on that indexing u can get the health and direction of a robot
          and whne all the processing is done then u should now that what is prevois ordering of the 
          robot's bcz based on that u have to fill survivedRobots.

          Now as we seen that stack is required but why I am not using stack rather than I am using 
          vector<pair<int, int>> st; // {index, health} bcz when we use the stack after all the 
          processing our stack contnatin {index, health} of the survived Robots now I have to fill 
          these health based on the previous ordering of the healts so first I have to insert all the
          stack elements into a vector then I ahve to sort that vector based on the indexs bcz these 
          are the indexs related to the prevois healths i.e. if ksi index ki value dusri index se kam
          h to eska mtlb hai ki vo index ki health phle likhni hai in your survivedRobots vector m

          so if we used direct a vector then we can sort this vector after entire processing.


T.C. = O(Nlog(N) +
       sort(pos.begin(), pos.end());    => O(Nlog(N))
       step -> 2: processign with stack => O(2*N)
       sort(st.begin(), st.end());      => O(Nlog(N))

S.C. = O(2*N + 2*N + N) ~~ O(N)
       vector<pair<int, int>> pos; => O(2*N)
       vector<pair<int, int>> st;  => O(2*N)
       vector<int> survivedRobots; => O(N)

*/
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> pos;  // {position, index}
        vector<pair<int, int>> st;   // {index, health}
        vector<int> survivedRobots;

        // step -> 1
        for(int i = 0; i < n; i++) {
            pos.push_back({positions[i], i});
        }
        sort(pos.begin(), pos.end()); // sort the pos vector based on the position

        // step -> 2
        for(int i = 0; i < n; i++) {
            int idx =  pos[i].second;
            int h   =  healths[idx];
            char d  =  directions[idx];

            if(st.empty()) {
                st.push_back({idx, h});
            } else {
                bool flag = true;
                while(!st.empty() && (directions[st.back().first] == 'R' && d == 'L')) {
                    if(h == st.back().second) {
                        st.pop_back();
                        flag = false;
                        break;
                    } else if(h < st.back().second) {
                        st.back().second -= 1;
                        flag = false;
                        break;
                    } else {
                        st.pop_back();
                        h -= 1;
                        flag = true;
                    }
                }

                if(flag) {
                    st.push_back({idx, h});
                }
            }
        }

        // step -> 3
        sort(st.begin(), st.end());
        for(int i = 0; i < st.size(); i++) {
            survivedRobots.push_back(st[i].second);
        }

        return survivedRobots;
    }
};