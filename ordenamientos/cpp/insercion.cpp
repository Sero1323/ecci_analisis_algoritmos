// Ordenamiento por insercion: O(n^2) en promedio y peor caso, O(n) si ya esta ordenado.
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int actual = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > actual) {
            v[j + 1] = v[j];  // se corre a la derecha
            --j;
        }
        v[j + 1] = actual;
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6};
    insertionSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
