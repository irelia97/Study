#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
 
typedef struct{
	int vexnum;	//顶点数 
	int arcnum;	//边数 
	unsigned **arc;	//邻接矩阵
	string *name; 
}Matrix_Graph;	
 
bool newGraph(Matrix_Graph& g)
{
	cout << "-------准备使用邻接矩阵法创建有向带权图-------" << endl;
	cout << "请输入顶点数和边数(空格隔开): ";
	cin  >> g.vexnum >> g.arcnum;
	//	图可以没有边，但不能没有顶点
	//	若有向图有n个顶点，则最多有n*(n-1)条边(有向完全图) 
	if( g.vexnum<0 || g.arcnum<=0 || g.arcnum>g.vexnum*(g.vexnum-1) ){
		cerr << "数据输入有误，请检查数据！" << endl; 
		g.vexnum = g.arcnum = 0;
		return false;
	}
	//	邻接矩阵初始化 
	g.arc  = new unsigned*[g.vexnum+1];
	g.name = new string[g.vexnum+1]; 
	for(int i = 1; i <= g.vexnum; ++i){
		g.name[i] = "V" + to_string(i);	//从1开始计数，边为V1, V2, V3... 
		g.arc[i]  = new unsigned[g.vexnum+1];
		for(int j = 1; j <= g.vexnum; ++j)
			g.arc[i][j] = INT_MAX;		//各边距离初始化为无穷大	
	}
	//	输入各边的权值
	int vstart, vend, weight;
	int n = g.arcnum;
	cout << "请输入" << n << "条有向边的起始顶点、终止顶点和权值(空格隔开)" << endl; 
	while( n-- ){
		cin >> vstart >> vend >> weight;
		g.arc[vstart][vend] = weight;	//有向图		
	}	 
	
	return true;		
}
void printRes(vector<string>& path, int *dist, int start)
{
	cout << "当前路径为："; 
	for(auto s : path)
		cout << s << ", ";
	cout << endl;
	
	cout << "源点到各点的最短路径值：" << endl; 
	for(int i = 1; i <= dist[0]; ++i){
		cout << "V"+to_string(start) << "->" << "V"+to_string(i) << ": ";
		if( dist[i] == INT_MAX )
			cout << "∞ ";
		else
			cout << dist[i] << " ";
		cout << endl;	 	
	}
	cout << endl;	
}
 
bool Dijkstra(const Matrix_Graph& g, int start = 1)
{
	int  i, j, k;
	//	存储源点到其它顶点的最短路径长度 
	int  dist[g.vexnum+1];
	for(i = 1; i <= g.vexnum; ++i)
		dist[i] = g.arc[start][i];
	dist[0] = g.vexnum;	
	//	存储已经访问过的结点 
	bool visited[g.vexnum+1] = {false};
	visited[start] = true;
	//	存储路径 
	vector<string> path;	//VT
	path.push_back( g.name[start] );
	
	int n = g.vexnum-1;
	while( n-- )
	{
		printRes(path, dist, start);
		int min = INT_MAX;
		//	找出dist[]中的最小权值顶点Vj 
		for(i = 1; i <= g.vexnum; ++i){
			if( !visited[i] && dist[i]<min ){
				min = dist[i];
				j = i;
			}
		}
		visited[j] = true;	
		path.push_back( g.name[j] );
		//	更新dist[] 
		for(k = 1; k <= g.vexnum; ++k){
			//	若源点到Vj的距离+Vj到Vk的距离
			//	小于源点到Vk的距离，更新
			//	至少有一个用unsigned存储，否则可能会上溢 
			if( dist[j]+g.arc[j][k]	< dist[k] )
				dist[k] = dist[j]+g.arc[j][k];	
		}	
	}	
	cout << "-------最后的结果是-------" << endl;	
	printRes(path, dist, start);
}
 
int main()
{    
    Matrix_Graph g;
    if( newGraph(g) ){
    	Dijkstra(g);
    } 
	
    return 0;
}