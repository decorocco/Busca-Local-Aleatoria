#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

struct item {
    int valor;
    int id;
    int peso;
};

int match(char a, char b) {
    if (a == b){
        return 2;
    }
    else{
        return -1;
    }
}

int score(vector<char> sa, vector<char> sb) {
    int result = 0;
    for(int i = 0; i < int(sa.size()); i++){
        result += match(sa[i], sb[i]);
    }
    return result;

}

int main() {

    int n = 0;
    int m = 0;

    vector<char> a;
    vector<char> b;
    vector<char> sa;
    vector<char> sb;

    cin >> n;
    cin >> m;

    char uni1;
    char uni2;

    int s = 0;
    int hs = 0;

    for(int i = 0; i < n; i++) {
        cin >> uni1;
        a.push_back(uni1);
    }
    for(int i = 0; i < m; i++){
        cin >> uni2;
        b.push_back(uni2);
    }

    int seed = 9909;
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, m);
    int k = distribution(generator);
    uniform_int_distribution<int> distributionj(0, m - k);
    int j = distributionj(generator);

    for(int i = j; i <= j+k; i++){
        sb.push_back(b[i]);
    }

    uniform_int_distribution<int> distributionp(0, 100);
    int p = distributionp(generator);

    for(int o = 0; o < p; o++){
        uniform_int_distribution<int> distributioni(0, n);
        int i = distributioni(generator);
        sa.clear();
        for(int q = i; q < i+k; q++){
            sa.push_back(a[o]);
        }

        s = score(sa, sb);
        if(s > hs){
            hs = s;
        }

    }

    cout << "Score:" << hs << endl;

    return 0;
}