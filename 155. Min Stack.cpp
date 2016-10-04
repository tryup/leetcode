class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    struct item
    {
        item(int lhs,int rhs):val(lhs),min(rhs) {
        }
        int val;
        int min;
    };

    void push(int x) {
        if( m_que.empty() ) {
            m_que.push( item(x,x) );
        }
        else{
            m_que.push( item(x, x< m_que.top().min ? x : m_que.top().min )); //每次都保存当前栈的最小值
        }
    }

    void pop() {
        m_que.pop();
    }

    int top() {
        return m_que.top().val;
    }
    //不进行时时计算。
    int getMin() {
        return m_que.top().min;
    }
private:
    stack<item> m_que;
};