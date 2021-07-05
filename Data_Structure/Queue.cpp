#include <bits/stdc++.h>
using namespace std;

class myQueue{
private:
    int* data;
    int  _front;
    int  _rear;
    int  _maxSize;
public:
    myQueue(int size = 5) : _maxSize(size+1), _front(0), _rear(0){
        data = new int[_maxSize];
        assert(data != nullptr);
    }
    ~myQueue() { delete[] data; }

    bool isEmpty() const { return _front == _rear; }
    bool isFull()  const { return (_rear+1)%_maxSize == _front; }
    int  size() const { return (_rear - _front + _maxSize) % _maxSize; }

    bool push(int x){
        if( isFull() )
            return false;
        data[_rear] = x;
        _rear = (_rear + 1) % _maxSize;
        return true;
    }
    bool pop(){
        if( isEmpty() )
            return false;
        _front = (_front + 1) % _maxSize;
        return true;
    }

    int& front() const{
        assert(!isEmpty());
        return data[_front];
    }
    int& back()  const{
        assert(!isEmpty());
        return data[(_rear - 1 + _maxSize) % _maxSize];       
    }
    friend ostream& operator<<(ostream& os, const myQueue& que);
};

ostream& operator<<(ostream& os, const myQueue& que){
    int i = que._front, j = que._rear;
    os << "front is " << i << ", rear is " << j << "\n";
    while( i != j ){
        os << que.data[i] << " ";
        i = (i + 1) % que._maxSize;
    }
    return os;
}

int main()
{
    myQueue que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(1);
    cout << que << endl;

    que.pop();
    que.push(10);
    que.push(11);
    cout << que << endl;

    return 0;
}