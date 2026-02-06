*This activity has been created as part of the 42 curriculum by wal-deek, raaalali.*

## Description
This repository contains an implementation of **push_swap**: sorting integers using two stacks (**a** and **b**) and a limited set of allowed operations. The program prints the operations (one per line) that sort stack **a** in ascending order.

The program embeds four strategies:
- Simple: quadratic strategy.
- Medium: chunk-based strategy.
- Complex: radix sort on indexed values.
- Adaptive: chooses a regime based on the computed disorder metric.

## Instructions
Build:
```sh
make
```
Run:
```sh
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```
Examples:
```sh
./push_swap 3 2 1
./push_swap --medium "5 1 4 2 3"
./push_swap --adaptive --bench 3 2 1 6 5 4
```

Notes:
- Input numbers are parsed from arguments split by spaces.
- Duplicates and out-of-range values are rejected.

## Resources
- 42 push_swap subject (v1.1)
- Common approaches: indexing + radix, chunk pushing, small-sort cases (2..5)

AI usage:
- Used as an assistant to review logic, propose refactors for Norminette limits, and help design the CLI flag and benchmark implementation.

## Algorithm overview
### Indexing
Values are copied into an array, sorted, checked for duplicates, then each node receives an increasing index. This normalizes values into a compact range.

### Simple strategy
A straightforward quadratic approach intended for small or nearly sorted cases.

### Medium strategy
Chunk strategy: push ranges of indices from **a** to **b**, then push back to **a** in descending order.

### Complex strategy
Radix sort using node indices.

### Adaptive strategy
Computes the disorder metric (pair inversions divided by total pairs) on the initial stack and chooses a regime:
- disorder < 0.2
- 0.2 <= disorder < 0.5
- disorder >= 0.5

When `--bench` is used, the program prints the computed disorder, selected strategy, complexity class, total operations, and per-operation counts to stderr.

## Group project contributions
- wal-deek: core stack implementation, parsing, indexing, and initial sorting algorithms.
- raaalali: refinements to sorting, dispatcher logic, and final cleanup.
