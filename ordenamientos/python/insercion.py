# Ordenamiento por insercion: O(n^2) en promedio y peor caso, O(n) si ya esta ordenado.


def insertion_sort(v):
    for i in range(1, len(v)):
        actual = v[i]
        j = i - 1
        while j >= 0 and v[j] > actual:
            v[j + 1] = v[j]  # se corre a la derecha
            j -= 1
        v[j + 1] = actual


if __name__ == "__main__":
    v = [12, 11, 13, 5, 6]
    insertion_sort(v)
    print(*v)
