#include <iostream>
#include <fstream>
#include "windows.h"
#include "Header.h"

using namespace std;

ifstream fin("input.txt");

int main()
{
	int Size;
	fin >> Size;
	int** matrix = new int* [Size];
	for (int i = 0; i < Size; i++)
	{
		matrix[i] = new int[Size];
		for (int j = 0; j < Size; j++)
		{
			fin >> matrix[i][j];
		}
	}
	Graph G1(Size, matrix);

	cout << "ALL COMBINATIONS:" << endl;

	G1.Gamiltons();
	return 0;
}
