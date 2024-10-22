
// vector<int> solve(int N, vector<vector<int>>& A) {
//     vector<int> positions, healths;
//     string directions;
//     int n = A.size();

//     // 1 -> Right, 0 -> Left
//     for (int i = 0; i < n; i++) {
//         int p = i;
//         int h = A[i][0];
//         char d = A[i][1] == 0 ? 'L' : 'R'; // L for Left, R for Right
//         positions.push_back(p);
//         healths.push_back(h);
//         directions.push_back(d);
//     }

//     vector<pair<int, int>> robot(n); // Store position and index
//     for (int i = 0; i < n; i++) // 0-indexed is fine
//         robot[i] = {positions[i], i};
    
//     // Sort robots in descending order of position
//     sort(robot.begin(), robot.end(), greater<>());

//     vector<int> stack; // To track robots moving left ('L')
//     for (auto& [pos, i] : robot) {
//         if (directions[i] == 'L') {
//             stack.push_back(i); // Store the index of robots moving left
//         } else {
//             // Resolve collisions with left-moving robots on the stack
//             while (!stack.empty() && healths[i] > 0) {
//                 int j = stack.back(); // Left-moving robot
//                 int health_diff = healths[j] - healths[i];
                
//                 if (health_diff > 0) {
//                     // Left-moving robot survives, right-moving robot dies
//                     healths[j] -= healths[i];
//                     healths[i] = 0;
//                 } else if (health_diff < 0) {
//                     // Right-moving robot survives, left-moving robot dies
//                     healths[i] -= healths[j];
//                     healths[j] = 0;
//                     stack.pop_back(); // Left-moving robot is knocked out
//                 } else {
//                     // Both robots die
//                     healths[i] = healths[j] = 0;
//                     stack.pop_back();
//                 }
//             }
//         }
//     }

//     vector<int> ans;
//     // Collect remaining robots with health > 0
//     for (int x : healths) {
//         if (x > 0) ans.push_back(x);
//     }
//     return ans;
// }

int solution(int N, int K, vector<int> candle) {
    map<int, int> mp;

    for (int i = 0; i < N; ++i) {
        mp[candle[i]] = i;
    }

    int maxi = INT_MIN, mini = INT_MAX;

    for (int i = 1; i <= K; ++i) {
        maxi = max(maxi, mp[i]);
        mini = min(mini, mp[i]);
    }

    return maxi - mini + 1;
}
