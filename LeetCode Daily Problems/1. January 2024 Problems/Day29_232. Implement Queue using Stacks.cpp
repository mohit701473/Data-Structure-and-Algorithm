https://leetcode.com/problems/implement-queue-using-stacks/description/


// T.C. = O(N^2)
// S.C. = O(2N)

class MyQueue {
public:
    stack<int> st1, st2 ;
    MyQueue() {
        st1 = stack<int> () ;
        st2 = stack<int> () ;
    }
    
    void push(int x) {
        st1.push(x) ;
    }
    
    int pop() {
        if(st1.size() <= 0)
            return -1 ;

        while(!st1.empty()){
            st2.push(st1.top()) ;
            st1.pop() ;
        }

        int ele = st2.top() ;
        st2.pop() ;

        while(!st2.empty()){
            st1.push(st2.top()) ;
            st2.pop() ;
        }

        return ele ;
    }
    
    int peek() {

        if(st1.size() <= 0)
            return -1 ;

        while(!st1.empty()){
            st2.push(st1.top()) ;
            st1.pop() ;
        }

        int ele = st2.top() ;

        while(!st2.empty()){
            st1.push(st2.top()) ;
            st2.pop() ;
        }

        return ele ;
    }
    
    bool empty() {
        return st1.empty() ;
    }
};




// Approch - 2:
// T.C. = O(N)
// S.C. = O(N)
class MyQueue {
public:
    stack<int> st1, st2 ;
    MyQueue() {
        st1 = stack<int> () ;
        st2 = stack<int> () ;
    }
    
    void push(int x) {
        st1.push(x) ;
    }
    
    int pop() {
        int ele = peek() ;
        st2.pop() ;
        return ele ;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top()), st1.pop() ;
            }
        }
        
        return st2.top() ;
    }
    
    bool empty() {
        return (st1.empty() && st2.empty()) ;
    }
};