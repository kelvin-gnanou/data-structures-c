# Data Structures in C

[![Status](https://img.shields.io/badge/status-in%20development-orange)]()
[![Language](https://img.shields.io/badge/language-C%20-blue)]()
[![License](https://img.shields.io/badge/license-MIT-green)]()
[![Focus](https://img.shields.io/badge/focus-data%20structures%20%26%20algorithms-purple)]()

> Educational implementations of classic data structures in **C11**. This repository brings together public interfaces, implementations, an interactive demonstration program, and a test suite built with `make`.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Build and Run](#build-and-run)
- [Tests](#tests)
- [Data Structures and API](#data-structures-and-api)
- [Repository Layout](#repository-layout)
- [Contributing](#contributing)
- [License](#license)

## Features

The project currently includes:

- a stack (LIFO);
- a queue (FIFO);
- a singly linked list;
- a binary search tree of integers;
- a graph represented by adjacency lists, supporting directed and undirected edges.

Each data structure has a public header and a separate implementation, with dynamically managed memory. `src/main.c` provides a menu for running demonstrations. The test suite covers the main operations of each structure.

## Prerequisites

- A C11-compatible compiler. The Makefile uses `clang` by default.
- GNU Make.

Check that they are available with:

```bash
clang --version
make --version
```

To use another compiler, pass it to `make`, for example: `make CC=gcc test`.

## Getting Started

```bash
git clone <repo>
cd data-structures-c
```

Replace `<repo>` with the repository URL [https://github.com/kelvin-gnanou/data-structures-c.git](https://github.com/kelvin-gnanou/data-structures-c.git). If you already have the project locally, change to its root directory.

## Build and Run

Build the main program:

```bash
make build
```

Run the interactive program:

```bash
make run
```

The menu lets you choose a demonstration: binary search tree, graph, linked list, queue, or stack. To build the program, run the tests, and then launch the program, use:

```bash
make
```

The default build configuration is debug (`-g -O0`). To build an optimized release version:

```bash
make BUILD=release build
```

Generated files are placed in `build/`.

## Tests

From the repository root, build and run the complete test suite with:

```bash
make test
```

The tests use assertions from the C standard library. A failed assertion terminates the test program with a non-zero exit status. If all assertions pass, each module reports its result and the program exits successfully.

To start from a clean build:

```bash
make clean
make test
```

## Data Structures and API

Public declarations are in `include/`; implementations are in `src/`.

| Data structure | Header | Main operations |
|---|---|---|
| Stack | `include/stack.h` | Create, push, pop, clear, get the size, and destroy |
| Queue | `include/queue.h` | Create, enqueue, dequeue, clear, get the size, and destroy |
| Singly linked list | `include/list.h` | Insert at either end, remove from either end or by value, clear, and destroy |
| Binary search tree | `include/binary_tree.h` | Insert, search, get the size and height, traverse in order, and destroy |
| Graph | `include/graph.h` | Create a directed or undirected graph, add an edge, get the vertex count, and destroy |

Functions that may fail during allocation or modification return a Boolean where the API provides one. Destruction functions accept a pointer to the structure pointer and set it to `NULL` after freeing the structure.

## Repository Layout

```text
.
├── include/        # Public data structure interfaces
├── src/            # Implementations and demonstration program
├── tests/          # Data structure tests
├── Makefile        # Build, demonstration, tests, and cleanup
├── LICENSE
└── README.md
```

The Makefile creates `build/bin/main.exe` for the application and `build/bin/test.exe` for the test suite.

## Contributing

Contributions are welcome. To propose a change:

1. Create a dedicated branch.
2. Make a focused change and add or update the relevant tests.
3. Verify the change with `make clean && make test`.
4. Open a pull request describing the problem and your solution.

## License

This project is distributed under the MIT License. See [LICENSE](LICENSE) for the full terms.
