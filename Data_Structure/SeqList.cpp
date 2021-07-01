#include <bits/stdc++.h>
using namespace std;

class SeqList{
private:
    int* arr;
    int  _size;
    int  _capacity;

    bool reAllocate(int defaultSize = -1){
        int newCapacity;
        if( defaultSize != -1 )
            newCapacity = defaultSize;
        else
            newCapacity = (_capacity == 0 ? 1 : _capacity*2);

        int *newArr = nullptr;
        if( (newArr = new int[newCapacity]) == nullptr ){
            cerr << "reAllocate failed!\n";
            return false;
        }

        memcpy(newArr, arr, sizeof(int) * _size);

        delete[] arr;
        arr = newArr;
        _capacity = newCapacity;

        return true;
    }
public:
    SeqList() : arr(nullptr), _size(0), _capacity(0) { }
    SeqList(int n, int x = 0) : _size(n), _capacity(n){
        arr = new int[n];
        for(int i = 0; i < n; ++i)
            arr[i] = x;
    }
    SeqList(const SeqList& anoList) : _size(anoList._size), _capacity(anoList._capacity){
        this->arr = new int[this->_capacity];
        for(int i = 0; i < this->_size; ++i)
            this->arr[i] = anoList.arr[i];
    }
    ~SeqList() { delete[] arr; }

    int size() const { return _size; }
    int capacity() const {  return _capacity; }
    int& operator[](const int index){
        if( index < 0 || index >= _size ){
            cerr << "Out of bound!\n";
            exit(-1);
        }
        return arr[index];
    }
    bool isEmpty() const{
        return _size == 0;
    }

    void resize(int newSize, int val = 0){
        if( newSize < 0 ) return;
        if( newSize > _size ){
            if( newSize > _capacity && !reAllocate(newSize) )
                return;
            for(int i = _size; i < newSize; ++i)
                arr[i] = val;
        } 
        _size = newSize;
    }

    void reserve(int newCapacity){
        if( newCapacity > _capacity ){
            reAllocate(newCapacity);
        }   
    }

    //  插入至下标为index的位置
    bool insert(const int data, const int index){
        if( index < 0 || index >= _size ){
            cerr << "Out of bound!\n";
            return false; 
        }
        //  扩容
        if( _size == _capacity && !reAllocate() ){
            return false;
        }
        int moveSize = _size - index;
        //  内存重叠，还未复制的部分被覆盖，会出错，改用memmove
        memmove(arr+index+1, arr+index, sizeof(int) * moveSize);

        arr[index] = data;
        _size++;
        return true;
    }  

    bool push_back(const int data){
        if( _size == _capacity ){
            if( !reAllocate() ){
                return false;
            }
        }
        arr[_size++] = data;
        return true;       
    }

    bool remove(const int index){
        if( index < 0 || index >= _size ){
            cerr << "Out of bound!\n";
            return false; 
        }
        int moveSize = _size - index - 1;
        //虽然内存重叠，但不会有影响
        memcpy(arr+index, arr+index+1, moveSize*sizeof(int));
        _size--;     
        return true;
    }

    bool pop_back(){
        if( isEmpty() ){
            cerr << "SeqList is empty!\n";
            return false;
        }
        _size--;
        return true;
    }

    int search(const int data) const{
        for(int i = 0; i < _size; ++i)
            if( arr[i] == data )
                return i;
        return -1;
    }

    void printInfo(string name) const{
        cout << name << " size is " << _size << ", capacity is " << _capacity << endl;
        for(int i = 0; i < _size; ++i)
            cout << arr[i] << " ";
        cout << "\n\n";
    }
};

int main()
{
    SeqList SL1;
    SL1.printInfo("SL1");
    SL1.push_back(123);
    SL1.printInfo("SL1");

    SL1.insert(7, 1);
    SL1.insert(9, 0);
    SL1.insert(887, 1);
    SL1.printInfo("SL1");
    SL1.insert(456, 1);
    SL1.printInfo("SL1");
    SL1.insert(576, 3);
    SL1.printInfo("SL1");
    SL1.remove(1);
    SL1.printInfo("SL1");

    SL1.pop_back();
    SL1.printInfo("SL1");

    SL1.reserve(5);
    SL1.printInfo("SL1");

    SL1.reserve(10);
    SL1.printInfo("SL1");

    SL1.resize(5);
    SL1.printInfo("SL1");

    SL1.resize(2);
    SL1.printInfo("SL1");

    return 0;
}
