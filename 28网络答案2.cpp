#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void built_pai(char P[], int pai[], size_t m) {
	int k{};
	pai[0] = 0;
	for (int q = 1; q < m; ++q) {
		while (k > 0 && P[k] != P[q]) {
			k = pai[k];
		}
		if (P[k] == P[q]) {
			k++;
		}
		pai[q] = k;
	}
}
 
void built_transform_function(int* theta, char* P, char* alpha, size_t m, size_t alpha_size) {
	int* pai = new int[m] {};
	built_pai(P, pai, m);
	for (int i = 0; i < alpha_size; ++i) {
		if (alpha[i] == P[0]) {
			theta[i] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < alpha_size; ++j) {
			if (P[i] == alpha[j]) {
				theta[i * alpha_size + j] = i + 1;
			}
			else {
				int tmp = pai[i - 1];
				if (P[tmp] == alpha[j]) {
					theta[i * alpha_size + j] = tmp + 1;
				}
				else if (alpha[j] == P[0]){
					theta[i * alpha_size + j] = 1;
				}
			}
		}
	}
	delete[]pai;
}
 
int find_index_of_alpha(char alpha[], char c, int alpha_size) {
	for (int i = 0; i < alpha_size; ++i) {
		if (alpha[i] == c) {
			return i;
		}
	}
	return -1;
}
 
void finite_automation_matcher(char T[], int theta[], char alpha[], int n, int m, int alpha_size) {
	int q{};
	for (int i = 0; i < n; ++i) {
		q = theta[q * alpha_size + find_index_of_alpha(alpha, T[i], alpha_size)];
		if (q == m) {
			cout << "Pattern occures with shit " << i - m << endl;
		}
	}
}
 
int main(int argc, char* argv[]) {
	vector<char> v{};
	char element{};
	cout << "please enter the sum of alphabet (end by '0') : " << endl;
	while (cin >> element) {
		if (element != '0') {
			v.push_back(element);
		}
		else {
			break;
		}
	}
	size_t alpha_size{ v.size() };
	char* alpha = new char[alpha_size] {};
	int index{};
	for_each(v.begin(), v.end(), [=](char x)mutable{ alpha[index++] = x; });
	v.clear();
	cout << "please enter the pattern (end by '0') : " << endl;
	while (cin >> element) {
		if (element != '0') {
			v.push_back(element);
		}
		else {
			break;
		}
	}
	size_t m{ v.size() };
	char* P = new char[m] {};
	index = 0;
	for_each(v.begin(), v.end(), [=](char x)mutable{ P[index++] = x; });
	int* theta = new int[(m + 1) * alpha_size] {};
	built_transform_function(theta, P, alpha, m, alpha_size);
	v.clear();
	cout << "please enter the text (end by '0') : " << endl;
	while (cin >> element) {
		if (element != '0') {
			v.push_back(element);
		}
		else {
			break;
		}
	}
	size_t n{ v.size() };
	char* T = new char[n] {};
	index = 0;
	for_each(v.begin(), v.end(), [=](char x)mutable{ T[index++] = x; });
	for (int i = 0; i < n; ++i) {
		cout << T[i] << " ";
	}
	cout << endl;
	finite_automation_matcher(T, theta, alpha, n, m, alpha_size);
	delete[]T;
	delete[]P;
	delete[]alpha;
	return 0;
}