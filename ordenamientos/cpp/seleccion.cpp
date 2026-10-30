// Ordenamiento por seleccion: O(n^2) siempre, con a lo sumo n-1 intercambios.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int menor = i;
        for (int j = i + 1; j < n; ++j) {
            if (v[j] < v[menor]) menor = j;
        }
        if (menor != i) swap(v[i], v[menor]);
    }
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};
    selectionSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
