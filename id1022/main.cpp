#include <iostream>

#define UNKNOWN_ANCESTOR -1
#define UNKNOWN 0
#define PROCESSING 1
#define FINISHED 2

#define xDEBUG

using namespace std;

typedef struct
{
	int discov;
	int finish;
	int state;
	int ancestor;
	int id;
} Vertex;

void dfs_visit(int vnum, int** g, Vertex *vertices, int cur_v, int &time)
{
	vertices[cur_v].discov = ++time;
	vertices[cur_v].state = PROCESSING;
	for (int i = 0; i < vnum; i++)
		if (g[cur_v][i] == 1 && vertices[i].state == UNKNOWN)
		{
			vertices[i].ancestor = cur_v;
			dfs_visit(vnum, g, vertices, i, time);
		}
	vertices[cur_v].state = FINISHED;
	vertices[cur_v].finish = ++time;
}

void dfs(int** g, int vnum, Vertex *vertices)
{
	for (int i = 0; i < vnum; i++)
	{
		vertices[i].state = UNKNOWN;
		vertices[i].ancestor = UNKNOWN_ANCESTOR;
		vertices[i].id = i + 1;
	}

	int time = 0;
	for (int i = 0; i < vnum; i++)
		if (vertices[i].state == UNKNOWN)
			dfs_visit(vnum, g, vertices, i, time);
}

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void sort_vertices(Vertex *vertices, int vnum)
{
	for (int i = 0; i < vnum; i++)
	{
		int cur_max = -1;
		int max_id = -1;
		for (int j = i; j < vnum; j++)
		{
			if (vertices[j].finish > cur_max)
			{
				cur_max = vertices[j].finish;
				max_id = j;
			}
		}
		swap(vertices[i].discov, vertices[max_id].discov);
		swap(vertices[i].finish, vertices[max_id].finish);
		swap(vertices[i].state, vertices[max_id].state);
		swap(vertices[i].ancestor, vertices[max_id].ancestor);
		swap(vertices[i].id, vertices[max_id].id);
	}
}

int main()
{
	int vnum;
	cin >> vnum;

	int **g = new int*[vnum];
	for (int i = 0; i < vnum; i++)
		g[i] = new int[vnum];
	for (int i = 0; i < vnum; i++)
	{
		int v;
		cin >> v;
		while (v != 0)
		{
			g[i][v-1] = 1;
			cin >> v;
		}
	}

	Vertex *vertices = new Vertex[vnum];

	dfs(g, vnum, vertices);

#ifdef DEBUG
	for (int i = 0; i < vnum; i++)
		cout << "Vertex: " << vertices[i].id << " discov: " << vertices[i].discov << " finish: " << vertices[i].finish
			 << " state: " << vertices[i].state << " ancestor: " << vertices[i].ancestor << endl;
#endif

	sort_vertices(vertices, vnum);

#ifdef DEBUG
	for (int i = 0; i < vnum; i++)
		cout << "Vertex: " << vertices[i].id << " discov: " << vertices[i].discov << " finish: " << vertices[i].finish
			 << " state: " << vertices[i].state << " ancestor: " << vertices[i].ancestor << endl;
#endif

	for (int i = 0; i < vnum; i++)
		cout << vertices[i].id << " ";

	for (int i = 0; i < vnum; i++)
		delete g[i];
	delete vertices;
	delete g;

	return 0;
}
