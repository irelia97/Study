#include <bits/stdc++.h>
using namespace std;

//	类型1和3中的比较，均是先按second非升序
//	相等则按first降序，故cmp函数统一 
bool cmp(const pair<string, int>& p1, 
	const pair<string, int>& p2)
{
	if( p1.second != p2.second )
		return p1.second > p2.second;
	else
		return p1.first < p2.first;
}

int main() 
{ 
	//	关闭同步，且映射均使用unordered_map
	//	否则cin, cout和map自动排序都会影响时间 
    ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	unordered_map<string, int> stu(N);
	
	string no;
	int grade;
	for(int i = 0; i < N; ++i){
		cin >> no >> grade;
		stu[no] = grade;
	}
	//	缓存已经得到过的结果，避免重复查找 
	unordered_map<string, vector<pair<string, int>>> m1;//级别，vec<准考证号，成绩> 
	unordered_map<string, pair<int, int>>    m2;		//考场编号，<人数，总分> 
	unordered_map<string, vector<pair<string, int>>> m3;//日期，vec<考场编号，人数> 
	//	缓存已经执行过的order，由于1,2,3号order长度不一
	//	所以不同类型order不会一样
	//	如此可以判断对该order是否进行过操作
	//	若存在，直接在m1,m2,m3中输出结果 
	unordered_set<string> set_order;
	
	int type;
	string order;
	for(int i = 1; i <= M; ++i){
		cin  >> type >> order;
		cout << "Case " << i << ": ";
		cout << type << " " << order << endl;
		
		switch(type){
			case 1:
				//	set中没有order说明未对该类操作过
				//	若有，则不需要再遍历vector，下同 
				if( set_order.find(order) == set_order.end() ){
					for(auto& s : stu){
						if( s.first[0] == order[0] )
							m1[order].emplace_back( make_pair(s.first, s.second) );
					}
					//	m1中含有order说明上面循环的if语句有执行
					//	即不为空，可以排序 
					if( m1.find(order) != m1.end() )
						sort(m1[order].begin(), m1[order].end(), cmp);
				}
				if( m1.find(order) != m1.end() ){
					auto& vec = m1[order];
					for(auto& x : vec)
						cout << x.first << " " << x.second << endl;
				}else{
					cout << "NA" << endl;
				}
				break;
			case 2:
				if( set_order.find(order) == set_order.end() ){
					for(auto& s : stu){
						if( s.first.substr(1,3) == order ){
							m2[order].first++;
							m2[order].second += s.second;
						}
					}
				}
				if( m2.find(order) != m2.end() )
					cout << m2[order].first << " " << m2[order].second << endl;
				else{
					cout << "NA" << endl;
				}
				break;
			case 3:
				if( set_order.find(order) == set_order.end() ){
					//	先用map保存考场编号和人数的关系 
					unordered_map<string, int> um;
					for(auto& s : stu){
						if( s.first.substr(4,6) == order ){
							um[s.first.substr(1,3)]++;
						}
					}
					//	若map非空则转为vector进行排序 
					if( um.size() > 0 ){
						auto& vec = m3[order];
						for(auto& x : um)
							vec.emplace_back(x);
						sort(vec.begin(), vec.end(), cmp);
					}
				}
				if( m3.find(order) != m3.end() ){
					auto& vec = m3[order];
					for(auto& x : vec)
						cout << x.first << " " << x.second << endl;
				}else{
					cout << "NA" << endl;
				}
				break;
			default:
				cout << "NA" << endl;
		}
		//	缓存order 
		set_order.insert(order);
	}
	
	return 0; 
}
