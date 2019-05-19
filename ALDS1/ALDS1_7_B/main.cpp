//  ALDS1_7_B  Tree - Binary Trees
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAX = 30;
const int NIL = -1;

struct Node
{
	int id = MAX;
	int parent = NIL;
	int left = NIL;
	int right = NIL;
	int sibling = NIL;
	int degree = NIL;
	int depth = NIL;
	int height = NIL;
};

Node nodes[MAX]; 
int numberOfnodes;

struct Nodes
{
		
	Nodes()
	{
		int parentId = getParentId();
		setDeps(parentId,0);
		setHeight(parentId);
	}

	int getParentId()
	{
		for (int i = 0; i < numberOfnodes; i++)
		{
			if(nodes[i].parent==NIL)
			{
				return nodes[i].id;
			}
		}
		return NIL;
	}	

	void setDeps(int id, int depth)
	{
		nodes[id].depth = depth;
		if (nodes[id].left != NIL ) setDeps(nodes[id].left, depth + 1);
		if (nodes[id].right != NIL ) setDeps(nodes[id].right, depth + 1);
	}

	int setHeight(int id)
	{
		int h1 = 0;
		int h2 = 0;
		
		if (nodes[id].right != NIL )
		{
			h1 = setHeight(nodes[id].right ) + 1;
		}

		if (nodes[id].left != NIL )
		{
			h2 = setHeight(nodes[id].left ) + 1;
		}

		nodes[id].height = max(h1,h2);

		return nodes[id].height;
	}

	string getType(int id)
	{
		if (nodes[id].parent == NIL ) return "root";
		else if (nodes[id].left == NIL && nodes[id].right == NIL) return "leaf";
		else return "internal node";
	}

	void dump()
	{
		for (int i = 0; i < numberOfnodes; i++)
		{
			printf("ID:%2d, parent:%2d, left:%2d, right:%2d\n"
				,nodes[i].id,nodes[i].parent,nodes[i].left,nodes[i].right);
		}
	}

	void print()
	{
        for (int i = 0; i < numberOfnodes; i++)
		{
			printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n"
				,nodes[i].id,nodes[i].parent,nodes[i].sibling,nodes[i].degree,nodes[i].depth,nodes[i].height,getType(nodes[i].id).c_str());
		}
	}
};

int main()
{
	cin >> numberOfnodes;

	for (int i=0;i<numberOfnodes;i++)
	{
		int num,left,right;
		cin >> num >> left >> right;
		nodes[num].id = num;
		nodes[num].left = left;
		nodes[num].right = right;
		if(left!=NIL)
			nodes[left].parent = num;
		if(right!=NIL)
			nodes[right].parent = num;
	}

	for (int i=0;i<numberOfnodes;i++)
	{
		//sibling
		if (nodes[i].parent != NIL)
		{
			if (nodes[nodes[i].parent].left == nodes[i].id)
			{
				nodes[i].sibling = nodes[nodes[i].parent].right;
			}

			if (nodes[nodes[i].parent].right == nodes[i].id)
			{
				nodes[i].sibling = nodes[nodes[i].parent].left;
			}
		}

		// degrees
		int deg = 0;
		if (nodes[i].left !=NIL) deg++;
		if (nodes[i].right != NIL) deg++;	
		nodes[i].degree = deg;
	}
	Nodes n;
	n.print();		
}