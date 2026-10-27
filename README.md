# ⚡ push_swap — Algoritmos de Ordenación con Dos Pilas

![Lenguaje](https://img.shields.io/badge/C-C99-A8B9CC?style=for-the-badge&logo=c)
![Escuela 42](https://img.shields.io/badge/Escuela_42-Algoritmos-000000?style=for-the-badge&logo=42)
![Algoritmo](https://img.shields.io/badge/Algoritmo-Radix_Sort_Binario-orange?style=for-the-badge)
![Complejidad](https://img.shields.io/badge/Complejidad-O(n%20%C2%B7%20b)-brightgreen?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-Aprobada-blue?style=for-the-badge)

**push_swap** es uno de los proyectos de algoritmia más desafiantes y reconocidos del currículo de **Escuela 42**. El reto consiste en ordenar un conjunto de enteros desordenados utilizando únicamente **dos pilas** (`Stack A` y `Stack B`) y un conjunto restringido de operaciones, minimizando al máximo la cantidad total de movimientos requeridos.

---

## 🎯 El Desafío

Dado un conjunto de enteros positivos y negativos sin duplicados en el `Stack A` y con el `Stack B` inicialmente vacío, se debe calcular e imprimir en salida estándar la secuencia óptima de instrucciones para dejar el `Stack A` ordenado de forma estrictamente ascendente.

### 🕹️ Conjunto de Operaciones Permitidas

| Operación | Descripción |
| :--- | :--- |
| `sa` / `sb` | **Swap:** Intercambia los dos primeros elementos en la cima de la pila A o B. |
| `ss` | Realiza `sa` y `sb` simultáneamente. |
| `pa` / `pb` | **Push:** Mueve el elemento superior de una pila y lo coloca en la cima de la otra (`pb`: de A hacia B; `pa`: de B hacia A). |
| `ra` / `rb` | **Rotate:** Desplaza todos los elementos de la pila hacia arriba una posición; el primer elemento pasa a ser el último. |
| `rr` | Realiza `ra` y `rb` simultáneamente. |
| `rra` / `rrb` | **Reverse Rotate:** Desplaza todos los elementos de la pila hacia abajo una posición; el último elemento pasa a ser el primero. |
| `rrr` | Realiza `rra` y `rrb` simultáneamente. |

---

## 🧠 Solución Algorítmica Implementada

Para resolver el problema con máxima eficiencia y escalabilidad, el proyecto implementa una arquitectura híbrida:

### 1. Pre-indexación / Compresión de Coordenadas
Antes de ordenar, el programa asigna a cada número un índice normalizado de `0` a `n - 1` en función de su valor relativo. Esto desacopla el algoritmo del valor absoluto de los números (manejando con igual facilidad enteros grandes o negativos) y reduce el espacio de representación a un rango continuo de índices enteros positivos.

### 2. Algoritmo Radix Sort Binario (Bitwise)
Para conjuntos medianos y grandes (100 y 500 números), se utiliza un **Radix Sort en base 2** operando bit a bit:
- Se determina la cantidad máxima de bits requeridos: $b = \lceil \log_2(n) \rceil$.
- En cada iteración $i$ (desde el bit menos significativo $0$ hasta $b - 1$):
  - Se inspecciona el bit $i$-ésimo de la cima del `Stack A`.
  - Si el bit es `0`, se desplaza a la pila B con `pb`.
  - Si el bit es `1`, se mantiene en la pila A rotando con `ra`.
  - Una vez procesados todos los elementos del `Stack A`, se devuelven todos los elementos del `Stack B` al `Stack A` con `pa`.
- **Complejidad temporal:** $\mathcal{O}(n \cdot b)$, lo que garantiza un número de movimientos estrictamente acotado y predecible, superando con creces los límites exigidos por la corrección de 42.

### 3. Casos Reducidos (Hardcoded Sorting)
Para cantidades pequeñas (2, 3 y 5 elementos), se aplican árboles de decisión y heurísticas deterministas para ordenar en el número mínimo teórico de pasos (por ejemplo, 3 números se ordenan en un máximo de 2 movimientos).

---

## 🏗️ Estructura del Proyecto

```text
push_swap/
│
├── 📂 includes/          # Cabeceras y prototipos de funciones
│   └── push_swap.h
│
├── 📂 src/               # Lógica del algoritmo y control
│   ├── push_swap.c       # Punto de entrada principal
│   ├── radix.c           # Implementación del Radix Sort binario
│   ├── sort.c            # Ordenación para casos pequeños (2, 3, 5)
│   ├── stack.c           # Inicialización y gestión de las pilas
│   ├── stack_utils.c     # Funciones auxiliares de las pilas
│   ├── arguments.c       # Parseo, validación y control de errores
│   ├── push.c            # Operaciones pa y pb
│   ├── swap.c            # Operaciones sa, sb y ss
│   ├── rotate_left.c     # Operaciones ra, rb y rr
│   └── rotate_rigth.c    # Operaciones rra, rrb y rrr
│
├── 📂 libft/             # Librería auxiliar C personalizada
├── Makefile              # Reglas de compilación automatizadas
├── checker_linux         # Binario de verificación de ordenación (Linux)
└── checker_Mac           # Binario de verificación de ordenación (macOS)
```

---

## 🛠️ Compilación y Uso

### 1. Compilación
```bash
make
```
Genera el ejecutable `push_swap`.

### 2. Ejecución Básica
Pasa como argumento la lista de números a ordenar:
```bash
./push_swap 4 67 3 87 23
```
*Salida:* Lista de instrucciones optimizadas (`pb`, `ra`, `pa`, etc.).

### 3. Verificación con el Checker
Comprueba que las instrucciones ordenan correctamente la pila:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
*Salida esperada:*
```text
OK
```

---

## 👨‍💻 Autor

- **Bernardo Luque** — [GitHub @BLL75](https://github.com/BLL75)
- Proyecto desarrollado bajo los estrictos estándares de la **Norma de Escuela 42**.
