#include <iostream>
#include <vector>
using namespace std;

//  最小堆
class minHeap{
private:
    static const int defaultSize = 30;
    vector<int> arr;
    int _size;
    int _maxSize;
    //  向下调整，将startPos元素下沉到合适位置，用于建最小堆
    void adjustDown(int startPos, int endPos){
        int i = startPos, j = 2*i + 1;
        int elem = arr[startPos];
        while( j <= endPos ){
            if( j+1 <= endPos && arr[j+1]<arr[j] )
                j++;
            if( elem <= arr[j] )
                break;
            else{
                arr[i] = arr[j];
                i = j;
                j = 2*i + 1;
            }
        }
        arr[i] = elem;
    }
    //  向上调整，将startPos元素上浮到合适位置，用于插入
    void adjustUp(int startPos, int endPos){
        int i = startPos, j = i / 2;
        int elem = arr[startPos];
        while( i > endPos ){
            if( elem < arr[j] ){
                arr[i] = arr[j];
                i = j;
                j = i / 2;
            }else{
                break;
            }   
        }
        arr[i] = elem;
    }
public:
    minHeap(const vector<int>& vec) : arr(vec), _size(vec.size()){
        _maxSize = vec.size() > defaultSize ? vec.size() : defaultSize; 
        arr.resize(_maxSize, 0);

        int adjustPos = (_size - 2) / 2;
        while( adjustPos >= 0 ){
            adjustDown(adjustPos--, _size - 1);
        } 
    }

    void insert(int elem){
        if( _size == _maxSize ){
            cerr << "Full!\n";
            return;
        }
        arr[_size++] = elem;
        adjustUp(0, _size - 1);
    }
    
    void pop(){
        if( _size == 0 ){
            cerr << "Empty!\n";
            return;
        }
        arr[0] = arr[_size - 1];
        _size--;
        adjustDown(0, _size - 1);
    }

    void printHeap(){
        for(int i = 0; i < _size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void heapSort(){
        for(int i = _size - 1; i > 0; --i){
            std::swap(arr[0], arr[i]);
            adjustDown(0, i - 1);
        }
    }
};

int main()
{
    vector<int> vec{53, 17, 78, 9, 45, 65, 87, 23};
    minHeap mh(vec);
    mh.printHeap();

    mh.heapSort();
    mh.printHeap();

    return 0;
}