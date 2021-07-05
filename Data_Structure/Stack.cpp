#include <bits/stdc++.h>
using namespace std;

class myStack{
private:
    int *stk;
    int _size;
    int _maxSize;

    void reAllocate(){
        int newMaxSize = _maxSize * 2;
        int *newStk = new int[newMaxSize];
        assert(newStk != nullptr);
        memcpy(newStk, stk, sizeof(int) * _maxSize);

        delete[] stk;
        stk = newStk;
        _maxSize = newMaxSize;
    }
public:
    myStack(int ms = 4) : _size(0), _maxSize(ms){
        stk = new int[ms];
        assert(stk != nullptr);
    }
    ~myStack(){
        delete[] stk;
    }

    bool isEmpty() const{ return _size == 0; }
    int size() const { return _size; }
    int maxSize() const { return _maxSize; }

    void push(int data){
        if( _size == _maxSize )
            reAllocate();
        stk[_size++] = data;
    }

    bool pop(){
        if( _size != 0 ){
            _size--;
            return true;
        }
        return false;
    }

    int& top() const{
        assert(_size != 0);
        return stk[_size - 1];
    }

    void makeEmpty() { _size = 0; }

    friend ostream& operator<<(ostream& os, const myStack& stack);
};

ostream& operator<<(ostream& os, const myStack& stack){
    os << "size is " << stack.size() << ", maxsize is " << stack.maxSize() << "\n";
    for(int i = 0; i < stack.size(); ++i)
        os << stack.stk[i] << " ";
    os << endl;
    return os;
}

int main()
{
    int size = 10;
    assert(size == 10);
    //  aseert内表达式为真，执行后面的语句
    myStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.pop();
    stk.push(4);
    cout << stk;

    stk.push(6);
    stk.push(10);
    cout << stk;

    //  共享栈
    const int maxSize = 100;
    int sharedStack[maxSize];
    int top1 = 0, top2 = maxSize - 1;
    //  入栈
    sharedStack[top1++] = 1;
    sharedStack[top2--] = 5;
    //  出栈
    top1--, top2++;
    //  栈空，栈满
    if( top1 + 1 == top2 )
        ;
    if( top1 == 0 || top2 == maxSize - 1 )
        ;

    return 0;
}
