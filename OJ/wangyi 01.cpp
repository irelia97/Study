#include <bits/stdc++.h>
using namespace std;

typedef struct point{
    int x, y;
    int front;  //路径前一个位置下标
    int dir;    //上一个位置走哪个方向到达此位置 0,1,2,3 ~ 上下左右
    point(int _x = 0, int _y = 0, int _no = -1):x(_x), y(_y), no(_no), front(-1){}

    point operator+(const point& ano){
        return point(x + ano.x, y + ano.y);
    }
    bool operator==(const point& ano){
        return x == ano.x && y == ano.y;
    }

    int no; //宝箱编号
    int md; //曼哈顿距离
    static bool cmp(const point& p1, const point& p2){
        if( p1.md != p2.md )
            return p1.md < p2.md;
        else
            return p1.no < p2.no;
    }
}Point;

Point dir[4] {Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1)};
vector<vector<char>> maze;
int T, m, n;

bool pointLegal(int x, int y, vector<vector<int>>& flag)
{
    return  (x>=0 && x<m) && (y>=0 && y<n) && (flag[x][y]==0)
        && (maze[x][y]=='.' || maze[x][y]=='*' || isdigit(maze[x][y]));
}

bool findPath(Point start, Point end, vector<Point>& path)
{
    vector<vector<int>> flag(m, vector<int>(n, 0));
    Point que[2500];
    que[0] = start;

    for(int i = 0, cnt = 1; i < cnt; ++i){
        if( que[i] == end ){
            Point p = que[i];
            while( p.front != -1 ){
                path.emplace_back(p);
                p = que[p.front];
            }
            return true;
        }
        for(int k = 0; k < 4; ++k){
            Point p = que[i] + dir[k];
            if( pointLegal(p.x, p.y, flag) ){
                flag[p.x][p.y] = 1;
                p.front = i;
                p.dir = k;
                que[cnt++] = p;
            }
        }
    }
    return false;
}

//  更新曼哈顿距离
bool updateMd(const Point& player, vector<Point>& treasure)
{
    Point firstT = treasure[0];
    for(auto& p : treasure)
        p.md = abs(player.x - p.x) + abs(player.y - p.y);
    sort(treasure.begin(), treasure.end(), Point::cmp);

    return firstT == treasure[0];   //判断宝物目标有没有改变
}

int main()
{
    
    cin >> T;
    while( T-- )
    {
        cin >> m >> n;
        vector<vector<char>>(m, vector<char>(n)).swap(maze);

        Point player;
        vector<Point> path;
        vector<Point> treasure;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin >> maze[i][j];
                if( maze[i][j] == '*' ){
                    player.x = i;
                    player.y = j;
                }else if( isdigit(maze[i][j]) )
                    treasure.emplace_back( Point(i, j, maze[i][j]-'0') );
            }
        }
        
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j)
        //         printf("%c ", maze[i][j]);
        //     putchar('\n');
        // }
        // putchar('\n');
        
        int  len = 0;
        bool canFind = true;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[player.x][player.y] = 1;

        vector<Point> totalPath;
        while( treasure.size() > 0 )
        {
            bool notChangeTarget = updateMd(player, treasure);
            //  需要更换路径：第一次进入 或 有其它宝箱曼哈顿距离更小
            if( (path.size() == 0) || (!notChangeTarget) ){
                // cout << "target is " << treasure[0].no << endl;
                path.clear();
                if( !findPath(player, treasure[0], path) ){
                    canFind = false;
                    break;
                }
            }
            // cout << path.size() << endl;
            // cout << "(" << player.x << ", " << player.y << "), direction is " << path.rbegin()->dir << endl;
            player = player + dir[path.rbegin()->dir];
            // cout << "now come to (" << player.x << ", " << player.y << ")\n";

            totalPath.emplace_back(player);
            if( visited[player.x][player.y] == 1 ){
                canFind = false;
                break;
            }
            visited[player.x][player.y] = 1;
            if( player == treasure[0] ){
                treasure.erase(treasure.begin());
                vector<vector<int>>(m, vector<int>(n, 0)).swap(visited);
            }

            path.pop_back();
            len++;
        }
        printf("%d\n", canFind ? len : -1);
    }
    return 0;
}