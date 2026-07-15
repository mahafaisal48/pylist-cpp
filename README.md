# PyList — A Python-Style List in C++

A C++ container that replicates the behavior of Python's built-in `list` — dynamic, heterogeneous, and Pythonic in interface — built using type erasure, templates, smart pointers, and operator overloading.

## Why This Exists
C++ is statically typed, so a single container normally can't hold `int`, `string`, `double`, and custom objects side by side the way Python's `list` can. `PyList` solves this with a **type-erasure pattern**, letting elements of any type live safely in the same container while preserving type-correct comparisons and printing.

## Design

### The Box System (Type Erasure)
- **`Box`** — an abstract base class defining a common interface: `print()`, `type()`, and `less()`.
- **`Boxed<T>`** — a templated derived class that stores an actual value of type `T` and implements the interface for that type.
- Elements are stored uniformly as `std::shared_ptr<Box>`, so a single `std::vector` can hold values of any type.
- `type()` (via `typeid`) enables safe runtime type checks before casting, so comparing or copying mismatched types fails safely instead of causing undefined behavior.

### PyList Class
Wraps `std::vector<std::shared_ptr<Box>>` and implements 20+ Python list-style operations:

| Category | Methods |
|---|---|
| Core list ops | `append`, `insert`, `remove`, `pop`, `pop(index)`, `extend`, `clear`, `reverse`, `sort`, `count`, `index`, `contains` |
| Pythonic operators | `operator[]` (supports negative indexing), `operator+`, `operator==`, `operator<`, `operator<<` |
| Slicing | `slice(start, end)` — supports negative indices like Python |
| Stack behavior | `push`, `pop_stack` |
| Queue behavior | `enqueue`, `dequeue` |
| Utility | `len`, `setitem`, `copy`, `begin`/`end` (range-based for loop support) |

Key design choices:
- **Smart pointers** (`shared_ptr`) — automatic memory management, no manual `delete`.
- **Negative indexing** — mirrors Python's `list[-1]` style access in `operator[]`, `setitem`, and `slice`.
- **Exception safety** — throws `std::out_of_range` for invalid indices/operations instead of undefined behavior.
- **Shallow copy semantics** — `extend` and `operator+` share ownership of elements via `shared_ptr`, matching Python's shallow-copy behavior for lists.

## Files
| File | Description |
|---|---|
| `container.h` | The `Box` / `Boxed<T>` type-erasure system |
| `pylist.h` | The `PyList` container class |
| `main.cpp` | Interactive menu-driven console tester exercising every operation |
| `docs/design_report.docx` | Full design report — rationale, challenges, and testing outcomes |

## Run It
```bash
g++ -std=c++17 main.cpp -o pylist_demo
./pylist_demo
```
This launches an interactive menu where you can append values of different types (int, string, char, double, float, custom `Person` struct, vector, or another `PyList`) and exercise any supported operation.

## Example
```cpp
PyList list1;
list1.append(5);
list1.append(10);
list1.append(3);
list1.sort();
std::cout << list1;   // [ 3 , 5 , 10 ]
```

## Author
Maha Faisal
