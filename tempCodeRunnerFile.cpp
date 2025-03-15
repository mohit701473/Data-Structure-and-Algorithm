// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int minProjects(vector<int> errorScore, int compP, int othQ) {
//     int n = errorScore.size();
//     int projects = 0;

//     sort(errorScore.rbegin(), errorScore.rend());

//     while (errorScore[0] > 0) { // Continue until all error scores become zero
//         errorScore[0] -= compP;

//         for (int i = 1; i < n; i++) {
//             if (errorScore[i] > 0) {
//                 errorScore[i] -= othQ;
//             }
//         }

//         projects++;

//         sort(errorScore.rbegin(), errorScore.rend());
//     }

//     return projects;
// }

// int main() {
//     // Input for errorScore_size
//     int errorScore_size;
//     cin >> errorScore_size;

//     vector<int> errorScore(errorScore_size);

//     // Input for the error scores of team members
//     for (int i = 0; i < errorScore_size; i++) {
//         cin >> errorScore[i];
//     }

//     // Input for compP and othQ
//     int compP, othQ;
//     cin >> compP >> othQ;

//     // Calculate the minimum number of projects
//     int result = minProjects(errorScore, compP, othQ);

//     // Output the result
//     cout << result << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int minProjects(vector<int> errorScore, int compP, int othQ) {
    priority_queue<int> maxHeap;
    for (int score : errorScore) {
        if (score > 0) {
            maxHeap.push(score);
        }
    }

    int projects = 0;
    while (!maxHeap.empty()) {
        int topScore = maxHeap.top();
        maxHeap.pop();
        topScore -= compP;
        vector<int> temp; // Temporarily store updated scores
        while (!maxHeap.empty()) {
            int otherScore = maxHeap.top();
            maxHeap.pop();
            if (otherScore > othQ) {
                temp.push_back(otherScore - othQ);
            }
        }

        if (topScore > 0) {
            maxHeap.push(topScore);
        }
        for (int newScore : temp) {
            maxHeap.push(newScore);
        }

        projects++;
    }

    return projects;
}

int main() {
    // Input for errorScore_size
    int errorScore_size;
    cin >> errorScore_size;

    vector<int> errorScore(errorScore_size);

    // Input for the error scores of team members
    for (int i = 0; i < errorScore_size; i++) {
        cin >> errorScore[i];
    }

    // Input for compP and othQ
    int compP, othQ;
    cin >> compP >> othQ;

    // Calculate the minimum number of projects
    int result = minProjects(errorScore, compP, othQ);

    // Output the result
    cout << result << endl;

    return 0;
}
