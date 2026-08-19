#include <iostream>
#include <list>
#include <vector>
#define max 11
// #include <queue>
using namespace std;
// Task 4: BFS_Traversal (Graph)
class Queue
{
public:
	int queue[max];
	int front;
	int back;
	bool is_empty()
	{
		if (front == -1 && back == -1)
		{
			return true;
		}
		return  false;
		
	}
	bool isFull()
	{
		if (back == (max - 1)) // Agr tail ka item index ke end pe pra ha to index full ha
		{
			return true;
		}
		else
			return false;
	}
	Queue()
	{
		front = -1;
		back = -1;
	}
	void push(int val)
	{
		if (isFull())
		{
			cout << "Queue is Full (Queue Overflow)" << endl;
		}
		else if (front == -1)
		{
			front = back = 0;
			queue[back] = val;
		}
		else
		{
			back++;
			queue[back] = val;
		}
	}
	void pop()
	{
		if (is_empty())
		{
			cout << "Queue is empty" << endl;
		}
		else if (front == back)
		{
			front = back = -1;
		}
		else
		{
			front = front + 1;  
		}
	}
	int get_front()
	{
		if (is_empty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		return queue[front];
	}
void get_front2()
{
	cout << "Front Element:" << endl;
	cout << queue[front] << endl;
}
void display()
{
for (int i = front; i <= back; i++)
{
	// int a = get_front()
	cout << queue[i] << " ";
	
}
cout<< endl;
}	
int back_val()   // STL jaisa naam "back" member variable se clash karega, isliye alag naam
{
	if (is_empty())
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	return queue[back];
}
int current_size()
{
	if (is_empty())
	{
		return 0;
	}
	return (back - front + 1);
}
};

// Graph
class AdjList_Graph
{
private:
	int v;
	list<int> *adjacencyList; // Dynamic array declaration: har index pe ek list of Integers bnai
public:
	AdjList_Graph(int v)
	{
		this->v = v;
		adjacencyList = new list<int>[v];
	}

	void Add_UnDirected_Edge(int u, int v)
	{
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}
	void AddDirected_Edge(int u, int v)
	{
		adjacencyList[u].push_back(v);
	}
	void PrintAdjList()
	{
		cout << "Adj list" << endl;
		for (int i = 0; i < v; i++)
		{
			cout << "Vertext " << i << " : ";
			for (int neigbh : adjacencyList[i])
			{
				cout << neigbh << " ";
			}
			cout << endl;
		}
	}
void BFS()
	{
		cout << "BFS Traversal" << endl;
		Queue q1;//class object
		vector<bool> vis(v, false);
		q1.push(0);	   // 0 se hm BFS start  kren ge
		vis[0] = true; // 0 hmara source node ha
		while (q1.current_size() > 0)
		{
			int u = q1.get_front(); // Q ka front ko print kr do
			q1.pop();			// Phir us front ko nikal do
			cout << u << " ";
			// Note: Push krte waqt hi visited ko true krna ha
			for (int v : adjacencyList[u]) // Jo queue se element nikala  ha us ke sare neigbhours ko check kro
			// v--> immediate neigbhours
			{ // agr koi neigbhour unvisited ha to  visited kr ke queue man push krdo
				if (!vis[v])
				{
					vis[v] = true;
					q1.push(v);
				}
			}
		}
	}	
};


main()
{
		AdjList_Graph g1(5); // 5 Vertices
	g1.Add_UnDirected_Edge(0, 1);
	g1.Add_UnDirected_Edge(1, 2); // Ye directed ha to ek edge ek dafa hi store krayen ge
	g1.Add_UnDirected_Edge(1, 3);
	g1.Add_UnDirected_Edge(2, 4);
	g1.PrintAdjList();
	g1.BFS();
	cout << endl;
	// g1.DFS();
}