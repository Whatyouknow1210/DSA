class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;++i)
        {
            int top = q.front();
            q.pop();
            q.push(top);
        }
    }
    
    int pop() {
        int p = q.front();
        q.pop();
        return p;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
    return !(q.size());
    }
};

/*
    Using 2 Queues:
    class MyStack {
        queue<int>q1,q2;
    public:
        MyStack() {

        }

        void push(int x) {
            q1.push(x);
        }
        int pop() {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int p = q1.front();
            q1.pop();
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            return p;
        } 
        int top() {
            int p = -1;
            while(!q1.empty())
            {
                p = q1.front();
                q2.push(p);
                q1.pop();
            }
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            return p;
        }

        bool empty() {
            return q1.size()==0?true:false;
        }
    };
 */