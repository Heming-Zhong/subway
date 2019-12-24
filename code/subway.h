#ifndef SUBWAY_H
#define SUBWAY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <string>

#define inf 66666666
using namespace std;

//�ߣ�(��㣬�յ㣬Ȩֵ)
struct edge
{
	int u, v, w;
	edge(int U, int V, int W = inf) :u(U), v(V), w(W) {  }
};

//���ݵ�����ѯϵͳ
class subway_system {
private:
	int n;	//վ̨��
	vector<list<pair<int, int>>>E;	//�ڽӱ�
	map<string, pair<string, int>> Stations;//վ̨��Ӧ����·�ͱ��
	vector<string> station_name;	//��Ŷ�Ӧ��վ̨

public:
	// zyj
	subway_system();
	void readData(vector<edge> &edges);
	void makeGraph(vector<edge> &edges);
	void checkLine(string origin, string destination);
	bool isStaition(string s) { return Stations.find(s) != Stations.end();}

	// zhm
	vector<int> getShortestPath(int a, int b);
};




#endif // !SUBWAY_H
