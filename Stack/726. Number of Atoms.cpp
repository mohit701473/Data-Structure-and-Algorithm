// LeetCode -> 726. Number of Atoms

/*
Approch -> Stack + Sorting + HashMap

Intuition -> First I just simply traverse the string and when I get a Atom then I count the 
             number of that Atom. mtbl Atom ke aage jo number lika a suppose "H2O" m jb mene
             Atom 'H' liya to uske bad usak number count = 2 bhi m kisi trh se count kr 
             lunga and for now es cheej {Atom : count} ko kisis data structure m store kr 
             lunga.

             Now jb ek open bracket aaye ga to uske corrosponding m ek close bracket bhi
             aaye ga and us close bracket ke bad m koi number ho bhi skta h or nhi bhi 
             Example: "H2(O)" or "Mg(OH)2"
             To agr number hua to vo number in brackets ke bich ke sbhi Atoms ke count ko 
             increase kr dega to increase krne ke liye mene apne data structure m piche tb 
             tk traverse kiya jb tk mere ko ek '(' nhi mil jata and traverse ke sath sabhi
             ke count ko increse kr diya and us opne bracket ko '(' mene '#' se replace kr
             diya taki vo aage kabhi kisi close bracket me issue na de
             Example: K4(ON(SO3)2)2
             phle mene {K:4} data structure me dal diya => [{K: 4}]
             => [{K:4}, {(:1}, {O:1}, {N:1}, {(:1}, {S:1}, {O:3}]
             and jese hi mene close bracket dekha to uske aage vale number ko count kr liya
             num = 2 and eske bad data structure pr tb tk piche chlta gya jb tk open bracket
             na mile and Atom ke count ko badata gya
             => [{K:4}, {(:1}, {O:1}, {N:1}, {(:1}, {S:1}, {O:3}] 
             {O:3} -> 3 * num = {O:6}
             {S:1} -> 1 * num = {S:2}
             {(:1} -> stop and convert this {#:1}
             => [{K:4}, {(:1}, {O:1}, {N:1}, {#:1}, {S:2}, {O:6}] 
             now further traverse on string and we encounter a ')' then do the same thing as
             above
             num = 2
             => [{K:4}, {(:1}, {O:1}, {N:1}, {#:1}, {S:2}, {O:6}] 
             {O:6} -> 6 * num = {O:12}
             {S:2} -> 2 * num = {S:4}
             {#:1} -> 1 * num = {#:2} agr humne '(' ko convert nhi kiya hota to vo yha issue krta
             {N:1} -> 1 * num = {N:2}
             {O:1} -> 1 * num = {O:2}
             {(:1} -> convert = {#:1}
             => [{K:4}, {#:1}, {O:2}, {N:2}, {#:2}, {S:4}, {O:12}]

             Now agr ')' ke bad m koi number na ho to
             Example: H2(O)K
             to es case m bhi hume piche aana hoga q ki hume es close bracket ke corresponding jo
             open bracket h use '#' me convert krna hoga and sath m ye bhi dhyan rhe ki agr number
             nhi h to to hum Atom ke count ko change na kre to es liye hum ne lika h ki
             num = num != 0 ? num : 1;

             Abhi tk humne processing part to dekh liya ki Atom and Count ko data structure m dal
             denge and close bracket aaye ga to piche jakr Atom's count ko update kr denge but
             Question is which data structure we should use and how we get the name of the Atom 
             and Count of the Atom bcz take an 
             Example: "(Kab421(ONa(SOa32)21)2)" & "Kba4(ONa(SOa3)21)2" -> Invalid Input
             Example: "KbNa4(ONa(SOa3)21)2"

             Here we can use data structure liek stack but the problem with stack is that jub 
             close bracket milega to sbhi Atom ko process krne ke bad vaps stack me bhi dal hoga 
             Q ki ye Atom further kise outer bracket ka bhi part ho skte h and stack kevel pop
             functionality hi provide krta h

             So here we sue a vector<pair<string, int>> vec

             now when the processing is complete we have to return asnwer in sorted fashion of the 
             Atom's name 
             So we use a map for sorting ke liye bhi or jo Atom's ka name same h unka count bhi 
             sum kr lenge esi liye vector pr direct sorting nhi lagai hum ne q ki us se same Name
             vale Atoms ke count ko sum nhi kr pate


T.C. = O(N^2)
S.C. = O(N)

*/
class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        int i = 0;
        vector<pair<string, int>> vec;
        map<string, int> mp;
        string ans = "";

        while(i < n) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                string temp = "";
                temp += s[i++];
                while(i < n && (s[i] >= 'a' && s[i] <= 'z')) {
                    temp += s[i++];
                }
                vec.push_back({temp, 1});
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while(i < n && (s[i] >= '0' && s[i] <= '9')) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                num = num != 0 ? num : 1;
                vec.back().second *= num;
            }
            else if(s[i] == '(') {
                vec.push_back({"(", 1});
                i++;
            }
            else { // s[i] = ')'
                i++;
                int num = 0;
                while(i < n && (s[i] >= '0' && s[i] <= '9')) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                num = num != 0 ? num : 1;

                int j = vec.size() - 1;
                while(j >= 0 && vec[j].first != "(") {
                    vec[j].second *= num;
                    j--;
                }
                if(j >= 0)
                    vec[j].first = "#";
            }
        }

        for(auto& it: vec) {
            mp[it.first] += it.second;
        }

        for(auto& it: mp) {
            if(it.first != "#") {
                ans += it.first;
                if(it.second != 1)
                    ans += to_string(it.second);
            }
        }

        return ans;
    }
};