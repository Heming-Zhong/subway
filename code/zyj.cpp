#include "subway.h"
#include "memu.h"

void subway_system::makeGraph(vector<edge>& edges) {
	list<pair<int, int>>tmp;
	for (int i = Stations.size(); i--; )
		E.push_back(tmp);
	for (auto& item : edges) {
		E[item.u].push_back(pair<int, int>(item.v, item.w));
		E[item.v].push_back(pair<int, int>(item.u, item.w));
	}
}

subway_system::subway_system() {
	vector<edge> edges;
	readData(edges);
/*	for (int i = 0; i < edges.size(); i++){
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		cout << station_name[u] << ' ' << station_name[v] << ' ' << w << endl;
	}*/
	makeGraph(edges);
}

void subway_system::readData(vector<edge>& edges) {
	ifstream fin("srcdata");
	int distance, ID[2];
	string line, station[2];

	while (fin >> line >> station[0] >> station[1] >> distance)
	{
		if (line.back() >= '0' && line.back() <= '9')line += "����";

		for (int i = 0; i < 2; i++)
		{
			auto findStation = Stations.find(station[i]);
			//���Ҳ�����վ��
			if (findStation == Stations.end()) {
				ID[i] = Stations.size();
				Stations[station[i]] = pair<string, int>(line, ID[i]);
				station_name.push_back(station[i]);
			}
			//��վ����������·��վ��
			else if ((*findStation).second.first == line)
				ID[i] = Stations[station[i]].second;
			//��վ��Ϊ����վ
			else
			{
				char c = '1';
				station[i] += c;
				auto it = Stations.find(station[i]);
				while (it != Stations.end() && (*it).second.first != line)
				{
					station[i].back() = ++c;
					it = Stations.find(station[i]);
				}
				if (it == Stations.end())
				{
					ID[i] = Stations.size();
					Stations[station[i]] = pair<string, int>(line, ID[i]);
					station_name.push_back(station[i]);
					string tmp = station[i];
					tmp.pop_back();
					edges.push_back(edge(ID[i], Stations[tmp].second, 0));
				}
				else
					ID[i] = Stations[station[i]].second;

			}
			
		}
		edges.push_back(edge(ID[0], ID[1], distance));
	}
	fin.close();
	n = Stations.size();
	//cout << Stations.size() << endl;
}


void reset(string &s){
	for(int i = 0; i < 5; i++)
		if(s.back()=='0' + i)
		{
			s.pop_back();
			return;
		}
}

void subway_system::checkLine(string origin, string destination) {
	int src = Stations[origin].second, target = Stations[destination].second;
	
	clear();
	if(src==target)
		cout << "���վ���յ�վ��ͬ";
	else
	{
		vector<string> transfer;
		vector<int> count(1);
		vector<string>line;
		string station1, station2;
		string line1, line2;
		vector<int> path = getShortestPath(src, target);	
		int u, v;
		
		int k = 1;
		cout << origin;
		while(k < path.size())
		{
			u = path[k-1], v = path[k];
			station1 = station_name[u];
			station2 = station_name[v];
			line1 = Stations[station1].first;
			line2 = Stations[station2].first;

			if(line1 == line2)
			{
				count.back()++;
				{
					string tmp = station2;
					reset(tmp);
					cout << "->" << tmp;
				}
				if (line.empty() || line1 != line.back())
					line.push_back(line1);
			}
			else
			{
				count.push_back(0);
				reset(station1);
				transfer.push_back(station1);
			}
			k++;
		}
		cout << endl;

		cout << "��" << origin << "��������" << line[0] << "��";
		for (int i = 0; i < transfer.size(); i++)
			cout << "��" << count[i] << "վ����" << transfer[i] << "������" << line[i + 1] << "��";
		cout << "���" << count.back() << "վ����" << destination << "��";

	}
	cout << endl;
	std::system("pause");
}