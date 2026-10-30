# Ordenamiento por residuos (radix sort): O(d * (n + b)), con d digitos en base b = 10.
# Requiere enteros no negativos.


def ordenar_por_digito(v, exp):
    """Ordena de forma estable segun el digito de valor posicional exp."""
    conteo = [0] * 10
    for x in v:
        conteo[(x // exp) % 10] += 1
    for d in range(1, 10):
        conteo[d] += conteo[d - 1]

    salida = [0] * len(v)
    for x in reversed(v):
        d = (x // exp) % 10
        conteo[d] -= 1
        salida[conteo[d]] = x
    v[:] = salida


def radix_sort(v):
    if not v:
        return

    mayor = max(v)
    exp = 1
    while mayor // exp > 0:
        ordenar_por_digito(v, exp)
        exp *= 10


if __name__ == "__main__":
    v = [170, 45, 75, 90, 802, 24, 2, 66]
    radix_sort(v)
    print(*v)
