//  ALDS1-ALDS1_7_A  Tree - Rooted Trees
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int MAX = 100005;
const int NIL = -1;

struct Node
{
	int parent = NIL;
	int left = NIL;
	int right = NIL;
};

Node T[MAX];
int n, D[MAX];

int getDepth(int u)
{
	int depth = 0;
	while (T[u].parent != NIL)
	{
		u = T[u].parent;
		depth++;
	}
	return depth;
}

void rec(int u, int p)
{
	D[u] = p;
	if (T[u].right != NIL ) rec(T[u].right, p); //右の兄弟に同じ深さを設定
	if (T[u].left != NIL ) rec(T[u].left, p+1); //もっとも左の子に自分の深さ＋1を設定
}

string getType(int u)
{
	if (T[u].parent == NIL ) return "root";
	else if (T[u].left == NIL) return "leaf";
	else return "internal node";
}

string getClidren(int u)
{
	string str = "[";
	if(T[u].left!=NIL)
	{
		int node = T[u].left;
		str += to_string(node);
		while (T[node].right != NIL)
		{
			node = T[node].right;
			str += ", " + to_string(node);
		}
	}
	str += "]";

	return str;
}

void printNodeStructs()
{
	for (int i = 0; i < n; i++)
	{
		printf("node %d p=%2d ,l=%2d, r=%2d, d=%2d, dr=%d,type=%s,%s\n",
		i,T[i].parent,T[i].left,T[i].right,getDepth(i),D[i],getType(i).c_str(),getClidren(i).c_str());
	}
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		printf("node %d: parent = %d, depth = %d, %s, %s\n",
		i,T[i].parent,D[i],getType(i).c_str(),getClidren(i).c_str());
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int vertex,depth, c, l;
		cin >> vertex >> depth;
		for (int j = 0; j < depth; j++)
		{
			cin >> c;
			if (j == 0)
			{
				T[vertex].left = c;
			}
			else
			{
				T[l].right = c;
			}
			l = c;
			T[c].parent = vertex;
		}
	}

	int r;
	for (int i = 0; i < n; i++)
	{
		if(T[i].parent == NIL ) {
			r = i;
		}
	}
	rec(r,0);
	
	//printNodeStructs();
	print();
	return 0;
}