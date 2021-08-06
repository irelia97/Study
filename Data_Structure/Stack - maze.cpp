#include <iostream>
#include <stack>
using namespace std;

typedef struct point{
    int x, y;
    int dir;//  表示该点下一个该搜索的方向，0~3对应右下左上，
            //  若为4表示各方向搜索失败，该点应退栈舍弃
    point(int _x = 0, int _y = 0):x(_x), y(_y), dir(0){}

    point operator+(const point& anoP){
        return point(x + anoP.x, y + anoP.y);
    }
    bool operator==(const point& anoP){
        return x == anoP.x && y == anoP.y;
    }   
}Point;

const int  row = 5;
const int  col = 5;
const char maze[row][col] = {
    ' ', '#', '#', ' ', ' ',
    ' ', ' ', ' ', ' ', '#',
    '#', '#', '#', ' ', ' ',
    ' ', '#', ' ', ' ', '#',
    ' ', ' ', ' ', '#', '#'
};
//  标记哪些点已经走过
bool tag[row][col];
//  右，下，左，上
const Point direction[4] = {Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)};
//  起点与终点
Point startP(0, 0), endP(4, 0);

bool postionLegal(int x, int y)
{
    return (x >= 0 && x < row) && (y >= 0 && y < col) 
        && (maze[x][y] == ' ') && (tag[x][y] == false);
}

void stackSearchMazePath()
{
    //  初始化工作
    stack<Point> path;
    path.emplace(startP);
    tag[startP.x][startP.y] = true;

    while( !path.empty() )
    {
        //  取引用，因为需要改变dir的值
        Point& topP = path.top();
        if( topP.dir < 4 ){
            //  探索dir方向，并自加准备探索下一个方向
            Point newP = topP + direction[topP.dir++];
            //  若新的位置合法则压栈，并标记为已探索
            if( postionLegal(newP.x, newP.y) ){
                tag[newP.x][newP.y] = true;
                path.emplace(newP);
            }
            if( newP == endP )
                break;
        }else{
            //  dir == 4，表示该位置所有方向都探索失败，弹出
            path.pop();
        }
    }
    //  若path不为空则输出从终点到起点的路径
    while( !path.empty() ){
        cout << path.top().x << ", " << path.top().y << endl;
        path.pop();
    }
}

int main()
{
    stackSearchMazePath();

    return 0;
}