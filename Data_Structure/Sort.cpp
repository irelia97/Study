#include <iostream>
#include <vector>
using namespace std;

void printVec(const vector<int>& vec)
{
    for(auto x : vec)
        cout << x << " ";
    cout << endl;
}

//  插入排序：直接插入、折半插入、希尔排序
//  直接插入排序
void directInsertSort(vector<int>& vec, int left, int right)
{
    int i, j, t;
    for(i = left + 1; i < right + 1; ++i){
        t = vec[i];
        for(j = i - 1; j>=left && vec[j]>t; --j)
            vec[j + 1] = vec[j];

        vec[j + 1] = t;
    }
}

//  选择排序
void selectSort(vector<int>& vec, int left, int right)
{
    for(int i = left; i <= right; ++i){
        int k = i;
        for(int j = i+1; j <= right; ++j){
            if( vec[j] < vec[k] )
                k = j;
        }
        std::swap(vec[i], vec[k]);
    }
}

//  折半插入排序
//  第i趟时前i-1个元素已经排好序，因此可用二分思想查找插入位置
void halfInsertSort(vector<int>& vec)
{
    for(int i = 1; i < vec.size(); ++i){
        int t = vec[i];
        int left = 0, right = i - 1;
        while( left <= right ){
            int mid = (left + right) / 2;
            if( vec[mid] > vec[i] )
                right = mid - 1;
            else
                left  = mid + 1;
        }
        for(int k = i; k > left; --k)
            vec[k] = vec[k-1];
        vec[left] = t;
    }
}

void shellSort(vector<int>& vec)
{
    //  步长从 n/2 每次减半，直到1
    for(int gap = vec.size() / 2; gap > 0; gap >>= 1){
        int i, k, t;
        for(i = gap; i < vec.size(); i++){
            t = vec[i];
            //  这里不是分别对每个组处理，而是对逐个元素的组进行直接插入排序
            for(k = i - gap; k>=0 && vec[k] > t;  k -= gap)
                vec[k + gap] = vec[k];
            vec[k + gap] = t;
        }
    }
}

//  快速排序
int Partition1(vector<int>& vec, int left, int right)
{
    // 一趟快速排序
    int t = vec[left];
    while( left < right ){
        while( left < right && vec[right] > t )
            right--;
        vec[left] = vec[right];

        while( left < right && vec[left] <= t )
            left++;
        vec[right] = vec[left];
    }
    vec[right] = t;    

    return right;
}

void myQuickSort1(vector<int>& vec, int left, int right)
{
    static const int M = 15;
    if( left >= right ) return;
    if( right - left <= M ){
        directInsertSort(vec, left, right);
        return;
    }   
    int mid = Partition1(vec, left, right);
    myQuickSort1(vec, left,  mid - 1);
    myQuickSort1(vec, mid + 1, right);
}

//  三路划分
void myQuickSort2(vector<int>& vec, const int left, const int right)
{
    if( left >= right ) return;
    //  i扫描元素
    int i = left;
    //  lessPos 表示小于pivot序列后一个位置
    //  rightPos表示大于pivot序列前一个位置
    int lessPos = left, rightPos = right;
    //  基准元
    const int pivot = vec[left];
    //  若条件不取等于，则需要在循环结束后自行交换
    while( i <= rightPos ){
        if( vec[i] < pivot ){
            std::swap(vec[i++], vec[lessPos++]);
        }else if( vec[i] > pivot ){
            //  此时i不移动，因为交换的vec[rightPos]的值未知，还需比较
            std::swap(vec[i], vec[rightPos--]);
        }else{
            i++;
        }
    }
    printVec(vec);

    myQuickSort2(vec, left, lessPos - 1);
    myQuickSort2(vec, rightPos + 1, right);
}

//  归并函数
void myMerge(vector<int>& vec, vector<int>& auxVec,
    int left, int right)
{
    int mid = (left + right) / 2;
    //  从左到右升序
    for(int i = left;  i <= mid; ++i)
        auxVec[i] = vec[i];
    //  从右到左升序
    for(int i = mid+1; i <= right; ++i)
        auxVec[right + mid + 1 - i] = vec[i];
    
    int i = left;
    while( left <= right ){
        if( auxVec[left] < auxVec[right] )
            vec[i++] = auxVec[left++];
        else
            vec[i++] = auxVec[right--];
    }
}

//  归并排序改进
void mergeSort_main(vector<int>& vec, vector<int>& auxVec,
    int left, int right)
{
    if( left >= right ) return;

    int mid = (left + right) / 2;
    mergeSort_main(vec, auxVec, left, mid);
    mergeSort_main(vec, auxVec, mid+1, right);
    myMerge(vec, auxVec, left, right);
}

void mergeSort(vector<int>& vec, int left, int right)
{
    vector<int> auxVec(vec);
    mergeSort_main(vec, auxVec, left, right);
}

//  基数排序
void radixSort(vector<int>& vec, int left, int right)
{
    int p = 1;
    while( true ){
        vector<int> radixVec[10];
        for(int i = left; i <= right; ++i)
            radixVec[vec[i] / p % 10].push_back(vec[i]);

        if( radixVec[0].size() == right - left + 1 ) 
            break;
        
        int index = left;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < radixVec[i].size(); ++j)
                vec[index++] = radixVec[i][j];
        }
        p *= 10;
    }
}

int main()
{
    vector<int> vec{22, 351, 13, 46, 45, 4, 13, 99, 58, 120};


    printVec(vec);
    // myQuickSort2(vec, 0, vec.size() - 1);
    // shellSort(vec);
    // directInsertSort(vec, 0, vec.size() - 1);
    // mergeSort(vec, 0, vec.size() - 1);
    // radixSort(vec, 2, 7);
    selectSort(vec, 0, vec.size() - 1);
    printVec(vec);

    return 0;
}