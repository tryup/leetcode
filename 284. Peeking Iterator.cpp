// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return Iterator(*this).next();
    }

};

//*************
//解析 题目要求,在peek的时候不能步进迭代器,又看到基类Iterator又一个拷贝构造函数，
//故可以产生一份拷贝进行工作,其余两个接口可以直接使用不用覆盖。
//当然也可以使用别的方法，但是需要引入外部变量来维护状态机，如果peek就调用next,如果next已经调用过了就cache一个值，
//这种应该是性能最高的。
//*************

