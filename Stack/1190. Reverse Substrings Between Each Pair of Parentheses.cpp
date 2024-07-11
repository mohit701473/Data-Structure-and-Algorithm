// LeetCode -> 1190. Reverse Substrings Between Each Pair of Parentheses
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/


class Solution {
public:
/*
Approch -> 2: RTL and LTR approch 

    when we are traversing a string and we encounter a '(' then know that we have to reverse the string which lies in between this '(' and corrosponding ')' the problem with the previous approch is reversing is taking O(N) and outer loop is also taking O(N) but one thing is compulsry that is we ahve to traverse the stirng so the outer loop we can't remove so some how we have to improve or manage reversing the string while traversing the string 
    
    one thing we can do like suppose "(abcd)" this is our example so while traversing whne we encounter a brackets we switch the i to its corrosponding open or close brackest and we also maintain a direction flag left_to_rirgh = true initiliy so that u know ok if LTR = true then 
i++ i.e. go to left directiona nand RTL = false then i-- go to right direction 

    the LTR and RTL switching is happen whne u encounter a bracket when u encounter a bracket then go to their corrosponding bracket and strat traversing according LRT flag and if character encounter thne insert into result string

how this remove reversing complexity
take this as an example -> ab(cde(ef))gh
first map all the brackets with their corrosponding brackets
now RTL = true and i = 0 and res = ""
ab(cde(ef))gh
i = 0 -> res += s[i] => res = "a" and i++
i = 1 -> res = res + s[i] => "ab" and i++;
i = 2 -> s[i] = '(' so switch to corrosponding ')' bracket and RTL = false
i = 10 -> i--
i = 9 -> s[i] = ')' switch and RTL = !RTL
i = 7 -> i++
i = 8 -> s[i] = e => res = res + e => "abe"

and so on


T.C. = O(N)  => Bcz we are toching each character at max once
S.C. = O(N)  => map and stack
*/
    string reverseParentheses(string s) {
        int n = s.size();
        bool RTL = true;
        string result = "";

        // step -> 1: Store the mapping of brackets into map
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                mp[st.top()] = i;
                mp[i] = st.top();
                st.pop();
            }
        }

        // step -> 2: traverse on the string
        int i = 0;
        while(i < n) {
            if(RTL) { // move left to right
                if(s[i] == '(' || s[i] == ')') {
                    i = mp[i];
                    i--;
                    RTL = !RTL;
                } else {
                    result += s[i];
                    i++;
                }
            } else { // move right to left
                if(s[i] == '(' || s[i] == ')') {
                    i = mp[i];
                    i++;
                    RTL = !RTL;
                } else {
                    result += s[i];
                    i--;
                }
            }
        }

        return result;    
    }
};





/*
    while traversing the string if we encounter '(' then just skit it and keep in mind that u have seen a '(' and when u encounter any character then just store it into result and when u encounter a ')' then u have to reverse the string but u should know that how much lengeth of the string should me reversed how u get know that
    for that just store the lengeth of the result stirng size when u encounter a '(' bcz when u are adding new characters into ur result that are belong after that '(' and when u encounter a ')' then u just skip that much of length and u can say that just simply 
revers(result.begin() + skipLen, result.end())
to store the skipLen u can use stack becasue last inserted '(' is first processed i.e. LIFO kind of processing

Example -> "ab(cde(ef))gh"
Example -> "ab(cde(ef))gf(ij(klm))pq"

Note -> In the question given that always reverse the innermost string fisrt but u can also reverse the outer most first also
Example -> "(u(love)i)"
process outer most first -> i(evol)u
process next brackets -> iloveu

T.C. = O(N^2)
S.C. = O(N)
*/

/*
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string result = "";
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(result.size());
            } else if(s[i] == ')') {
                int skipLen = st.top();
                st.pop();
                reverse(result.begin() + skipLen, result.end());
            } else {
                result += s[i];
            }
        }

        return result;
    }
};
*/



/*
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;

        while(i < n) {
            while(i < n && s[i] != '(') {
                ans += s[i++];
            }

            stack<string> st;
            bool flag = true;
            while(i < n) {
                string str = "";
                str += s[i++];
                if(str == ")") {
                    str = "";
                    while(!st.empty() && st.top() != "(") {
                        reverse(st.top().begin(), st.top().end());
                        str += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                
                if(!flag && st.empty()) {
                    ans += str;
                    flag = false;
                    break;
                }
                flag = false;
                st.push(str);
            }
        }

        return ans;
    }
};
*/