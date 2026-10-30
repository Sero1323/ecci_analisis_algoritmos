# Ordenamiento por seleccion: O(n^2) siempre, con a lo sumo n-1 intercambios.


def selection_sort(v):
    n = len(v)
    for i in range(n - 1):
        menor = i
        for j in range(i + 1, n):
            if v[j] < v[menor]:
                menor = j
        if menor != i:
            v[i], v[menor] = v[menor], v[i]


if __name__ == "__main__":
    v = [64, 25, 12, 22, 11]
    selection_sort(v)
    print(*v)
