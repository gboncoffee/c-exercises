#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>

using namespace std;
using matrix = vector<vector<double>>;

int solve(matrix *s)
{
	// TODO

	return 1;
}

void read_system(matrix *m)
{
	for (unsigned long i = 0; i < m->size(); i++) {
		cout << "Enter " << i + 1 << " line: " << flush;
		for (unsigned long j = 0; j < (*m)[0].size() - 1; j++)
			cin >> (*m)[i][j];
	}

	cout << "Enter right side: " << flush;

	for (unsigned long i = 0; i < m->size(); i++)
		cin >> (*m)[i][(*m)[0].size() - 1];
}

void print_matrix(matrix *m) {
	for (unsigned long i = 0; i < m->size(); i++) {
		cout << "[";
		for (unsigned long j = 0; j < (*m)[0].size() - 1; j++)
			cout << (*m)[i][j] << ", ";
		cout << (*m)[i][(*m)[0].size() - 1] << "]" << endl;
	}
}

int clone_matrix(matrix *dest, matrix *src)
{
	if (dest->size() != src->size()
	    || (*dest)[0].size() != (*src)[0].size())
		return 1;

	for (unsigned long i = 0; i < src->size(); i++)
		for (unsigned long j = 0; j < (*src)[0].size(); j++)
			(*dest)[i][j] = (*src)[i][j];

	return 0;
}

void print_sol(matrix *sol)
{
	int j = (*sol)[0].size() - 1;
	cout << "(";
	for (unsigned long i = 0; i < (sol->size() - 1); i++) {
		cout << (*sol)[i][j] << ", ";
	}
	cout << (*sol)[sol->size() - 1][j] << ")^T" << endl;
}

int main(void)
{
	int m, n;
	cout << "Enter the size of the system (e.g., 3x3, 4x5, etc): " << flush;
	while (scanf("%dx%d", &m, &n) != 2);

	if ((!m) || (!n)) {
		cerr << "No system can have 0 on size!" << endl;
		return 1;
	}

	matrix s(m, vector<double>(n + 1));
	read_system(&s);
	cout << endl;
	print_matrix(&s);

	matrix sol(m, vector<double>(n + 1));
	clone_matrix(&sol, &s);

	switch (solve(&sol)) {
	case -1:
		cout << "Infinite solutions" << endl;
		break;
	case 0:
		cout << "Solution: ";
		print_matrix(&sol);
		print_sol(&sol);
		break;
	case 1:
		cout << "No solutions" << endl;
		break;
	}

	return 0;
}
