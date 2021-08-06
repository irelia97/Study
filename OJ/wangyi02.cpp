#include <bits/stdc++.h>
using namespace std;

typedef struct info{
    int realIndex;
    int sum;
    info(int r, int s):realIndex(r), sum(s){}
}Info;

int main()
{
    int N;
    while( cin >> N )
    {
        vector<vector<int>> nums(N);
        vector<int> rowSum(N, 0), colSum(N, 0);

        for(int i = 0; i < N; ++i){
            nums[i].resize(N);
            for(int j = 0; j < N; ++j){
                cin >> nums[i][j];
                rowSum[i] += nums[i][j];
                colSum[j] += nums[i][j];
            }
        }

        vector<Info> rowInfo, colInfo;
        for(int i = 0; i < N; ++i){
            rowInfo.emplace_back( Info(i, rowSum[i]) );
            colInfo.emplace_back( Info(i, colSum[i]) );
        }

        for(int t = 0; t < N; ++t){
            int maxSum = 0;
            int maxi = 0, maxj = 0;
            for(int i = 0; i < N - t; ++i){
                for(int j = 0; j < N - t; ++j){
                    int realNum = nums[rowInfo[i].realIndex][colInfo[j].realIndex];
                    if( rowInfo[i].sum + colInfo[j].sum - realNum> maxSum ){
                        maxSum = rowInfo[i].sum + colInfo[j].sum - realNum;
                        maxi = i;
                        maxj = j;
                    }
                }
            }
            // cout << maxi << "," << maxj << " maxSum = " << maxSum << "\n\n";
            cout << maxi + 1 << " " << maxj + 1 << "\n";

            //  更新Info
            for(int i = 0; i < N - t; ++i){
                rowInfo[i].sum -= nums[rowInfo[i].realIndex][colInfo[maxj].realIndex];
                colInfo[i].sum -= nums[rowInfo[maxi].realIndex][colInfo[i].realIndex];
            }
      
            rowInfo.erase(rowInfo.begin() + maxi);
            colInfo.erase(colInfo.begin() + maxj);

            // cout << "rowInfo : \n";
            // for(int i = 0; i < rowInfo.size(); ++i){
            //     cout << "real index" << rowInfo[i].realIndex << ", sum " << rowInfo[i].sum << endl;
            // }

            // cout << "colInfo : \n";
            // for(int i = 0; i < colInfo.size(); ++i){
            //     cout << "real index" << colInfo[i].realIndex << ", sum " << colInfo[i].sum << endl;
            // }   
        }
    }

    return 0;
}