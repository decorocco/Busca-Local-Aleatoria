#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

struct item {
    int valor;
    int linha;
    int coluna;
    int tipo; // diagonal = 1, deleção = 2, inserção = 3, zero = 4
};

int main() {
    default_random_engine generator(10);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    int n = 0;
    int m = 0;

    string a;
    string b;

    cin >> n >> m;
    cin >> a >> b;

    

    item H[n+1][m+1];
}