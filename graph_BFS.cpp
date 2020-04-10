#include<iostream>
#include<list>
#include<vector> 
using namespace std;

class Graph {
	int order;
	vector<vector<int>> adjList;
public:
	Graph(int V);
	void addEdge(int src, int dest);
	void DFS(int vertex);
};

Graph::Graph(int vertices)
{
	order = vertices;
	adjList.resize(order);
}

void Graph::addEdge(int src, int dest)
{
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}
void Graph::DFS(int vertex) {
	list<int> queue;
	vector<bool> visited(order, false);
	queue.push_back(vertex);
	while (!queue.empty()) {
		int current = queue.front();
		queue.pop_front();
		if (!visited[current])
		{
			cout << current << " ";
			visited[current] = true;
		}
		for (int &x : adjList[current]) {
			if (!visited[x]) { queue.push_back(x); }
		}
	}
}
int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.DFS(2);
	cin.get();
	return 0;
}