#pragma once
#pragma once
#define NULL 0
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream fout("output.txt");

class Graph
{
private:
	int _size;
	int** _graph;
	vector<int> _points;
	vector<vector<int>>_gamiltons;

	void P(int l = 0)
	{
		if (l == _size - 1)
		{
			Print(_points);
			/*обрабатываем получившийся массив*/
			if (Check())
			{
				_gamiltons.push_back(_points);
			}
			return;
		}
		for (int i = l; i < _size; i++)
		{
			swap(_points[i], _points[l]);
			P(l + 1);
		}
		for (int i = l + 1; i < _size; i++)
		{
			swap(_points[i - 1], _points[i]);
		}
	}

	void Print(vector<int>arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}

	bool Check()
	{
		for (int i = 0; i < _size - 1; i++)
		{
			if (_graph[_points[i]][_points[i + 1]] == -1)
			{
				return false;
			}
		}
		if (_graph[_points[0]][_points[_size - 1]] == -1)
		{
			return false;
		}
		return true;
	}

public:
	Graph()
	{
		_size = 0;
		_graph = NULL;
		for (int i = 0; i < _size; i++)
		{
			_points[i] = i;
		}
	}

	Graph(int size, int** Graph)
	{
		_size = size;
		_graph = new int* [_size];
		for (int i = 0; i < _size; i++)
		{
			_graph[i] = new int[_size];
			for (int j = 0; j < _size; j++)
			{
				_graph[i][j] = Graph[i][j];
			}
		}
		for (int i = 0; i < _size; i++)
		{
			_points.push_back(i);
		}
	}
	
	void Gamiltons()
	{
		P(1);
		cout << "Gamiltons:" << endl;
		int min_dist = INT32_MAX;
		vector<int>min_vector;
		for (int i = 0; i < _gamiltons.size(); i++)
		{
			Print(_gamiltons[i]);
			int distance = 0;
			for (int j = 0; j < _gamiltons[i].size() - 1; j++)
			{
				distance += _graph[_gamiltons[i][j]][_gamiltons[i][j + 1]];
			}
			distance += _graph[_gamiltons[i][0]][_gamiltons[i][_gamiltons[i].size() - 1]];
			cout << "Distance: " << distance << endl;
			if (distance < min_dist)
			{
				min_dist = distance;
				min_vector = _gamiltons[i];
			}
		}
		cout << "Count = " << _gamiltons.size() << endl << endl << endl;
		cout << "Min: ";
		Print(min_vector);
		cout << "Minimal Distance: " << min_dist << endl;
	}

	~Graph()
	{
		_size = 0;
		for (int i = 0; i < _size; i++)
		{
			delete[] _graph[i];
		}
		delete[] _graph;
	}
};
