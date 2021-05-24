#include <bits/stdc++.h>
using namespace std;

//	����1��3�еıȽϣ������Ȱ�second������
//	�����first���򣬹�cmp����ͳһ 
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
	//	�ر�ͬ������ӳ���ʹ��unordered_map
	//	����cin, cout��map�Զ����򶼻�Ӱ��ʱ�� 
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
	//	�����Ѿ��õ����Ľ���������ظ����� 
	unordered_map<string, vector<pair<string, int>>> m1;//����vec<׼��֤�ţ��ɼ�> 
	unordered_map<string, pair<int, int>>    m2;		//������ţ�<�������ܷ�> 
	unordered_map<string, vector<pair<string, int>>> m3;//���ڣ�vec<������ţ�����> 
	//	�����Ѿ�ִ�й���order������1,2,3��order���Ȳ�һ
	//	���Բ�ͬ����order����һ��
	//	��˿����ж϶Ը�order�Ƿ���й�����
	//	�����ڣ�ֱ����m1,m2,m3�������� 
	unordered_set<string> set_order;
	
	int type;
	string order;
	for(int i = 1; i <= M; ++i){
		cin  >> type >> order;
		cout << "Case " << i << ": ";
		cout << type << " " << order << endl;
		
		switch(type){
			case 1:
				//	set��û��order˵��δ�Ը��������
				//	���У�����Ҫ�ٱ���vector����ͬ 
				if( set_order.find(order) == set_order.end() ){
					for(auto& s : stu){
						if( s.first[0] == order[0] )
							m1[order].emplace_back( make_pair(s.first, s.second) );
					}
					//	m1�к���order˵������ѭ����if�����ִ��
					//	����Ϊ�գ��������� 
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
					//	����map���濼����ź������Ĺ�ϵ 
					unordered_map<string, int> um;
					for(auto& s : stu){
						if( s.first.substr(4,6) == order ){
							um[s.first.substr(1,3)]++;
						}
					}
					//	��map�ǿ���תΪvector�������� 
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
		//	����order 
		set_order.insert(order);
	}
	
	return 0; 
}
