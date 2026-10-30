# Ordenamiento por conteo (counting sort): O(n + k), con k el valor maximo. Estable.
# Requiere enteros no negativos.


def counting_sort(v):
    if not v:
        return

    k = max(v)
    conteo = [0] * (k + 1)
    for x in v:
        conteo[x] += 1

    # Suma acumulada: conteo[x] es la posicion donde termina x en la salida.
    for x in range(1, k + 1):
        conteo[x] += conteo[x - 1]

    # Se recorre de atras hacia adelante para conservar la estabilidad.
    salida = [0] * len(v)
    for x in reversed(v):
        conteo[x] -= 1
        salida[conteo[x]] = x
    v[:] = salida


if __name__ == "__main__":
    v = [2, 5, 3, 0, 2, 3, 0, 3]
    counting_sort(v)
    print(*v)
