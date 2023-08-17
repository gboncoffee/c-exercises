#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<double>>;

void multiply_sum_lines(vector<double> *p, vector<double> *l, unsigned long start)
{
	double fact = (*p)[start] / (*l)[start];
	for (unsigned long i = start; i < (*p).size(); i++) {
		(*l)[i] *= -fact;
		(*l)[i] += (*p)[i];
	}
}

int solve(matrix *s)
{
	for (unsigned long i = 0; i < (*s).size() - 1; i++)
		for (unsigned long j = (i + 1); j < (*s).size(); j++)
			multiply_sum_lines(&(*s)[i], &(*s)[j], i);

	// TODO: Use result from Gauss' Elimination to get the solution of the
	// system.

	return 0;
}

void read_system(matrix *m)
{
	for (unsigned long i = 0; i < m->size(); i++)
		for (unsigned long j = 0; j < (*m)[0].size() - 1; j++)
			cin >> (*m)[i][j];

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
	cin >> m >> n;

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
		cout << endl;
		print_matrix(&sol);
		// print_sol(&sol);
		break;
	case 1:
		cout << "No solutions" << endl;
		break;
	}

	return 0;
}
