*This project has been created as part of the 42 curriculum by salegari, marlope3.*

# Push_swap

## Description

Push_swap is a sorting project written in C. Its goal is to sort a stack of unique integers in ascending order using a second stack and a restricted set of operations, while keeping the number of generated operations as low as possible.

Initially, stack A contains the input numbers and stack B is empty. The first argument is the top of stack A. At the end, the smallest number must be at the top of A and B must be empty.

The program provides three explicit sorting strategies and an adaptive selector based on the initial disorder of the input. An optional benchmark mode reports the disorder, selected strategy and operation counts to standard error. Sorting instructions are written to standard output.

The bonus program, `checker`, reads operations from standard input, applies them to the supplied numbers and checks the final stack configuration.

## Instructions

### Requirements and compilation

The project requires a C compiler (`cc`) and Make. The bundled Libft is built by the Makefile.

```sh
git clone https://github.com/MarioLoppp/PushSwap.git
cd PushSwap
make
```

| Command | Purpose |
| --- | --- |
| `make` | Build `push_swap` and its Libft dependency |
| `make bonus` | Build the bonus `checker` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, executables and the compiled library |
| `make re` | Perform a clean rebuild |

The compiler flags are `-Wall -Wextra -Werror -g3`.

### Running Push_swap

```sh
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

Flags must appear before the numbers. The benchmark flag and strategy selector may appear in either order. Only one strategy selector and one benchmark flag are accepted.

```sh
./push_swap 5 2 4 1 3
./push_swap --simple 5 2 4 1 3
./push_swap --medium "5 2 4 1 3"
./push_swap --complex 5 2 4 1 3
./push_swap --adaptive --bench 5 2 4 1 3
./push_swap --bench --complex 5 2 4 1 3
```

| Flag | Behavior |
| --- | --- |
| `--simple` | Run the bubble-sort adaptation |
| `--medium` | Run the indexed sliding-window strategy |
| `--complex` | Run binary LSD radix sort |
| `--adaptive` | Select a strategy using the initial disorder; this is the default |
| `--bench` | Write benchmark information to standard error |

Inputs must be unique signed integers in the range `INT_MIN` to `INT_MAX`. Invalid numbers, duplicates, out-of-range values and invalid flag combinations produce `Error` followed by a newline on standard error. With no arguments, the program produces no output. Already sorted inputs produce no sorting operations.

### Benchmark mode

The benchmark reports the initial disorder as a percentage with two decimal places, the selected strategy and its complexity label, the total operation count and the count of each operation type.

```sh
./push_swap --bench --complex 5 2 4 1 3 > operations.txt 2> benchmark.txt
```

This saves the sorting instructions and benchmark report separately. Complexity labels describe the selected method; they do not certify compliance with every adaptive complexity target discussed below.

### Bonus checker

```sh
make bonus
./push_swap --complex 5 2 4 1 3 | ./checker 5 2 4 1 3
```

The checker prints `OK` if A is sorted and B is empty after all operations, or `KO` otherwise. Invalid input or an invalid operation produces `Error`. For interactive use, enter one operation per line and end the input with EOF (`Ctrl+D` on an empty line).

## Stack operations and representation

Both stacks use doubly linked nodes containing the original integer and its normalized index. Stack metadata stores the top, bottom, size and stack name. Normalized indices are ranks from `0` to `n - 1`, preserving the order of the original values.

| Operations | Effect |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the first two elements of A, B or both |
| `pa`, `pb` | Push the top element from B to A, or from A to B |
| `ra`, `rb`, `rr` | Move the top element to the bottom of A, B or both |
| `rra`, `rrb`, `rrr` | Move the bottom element to the top of A, B or both |

An operation that cannot act on a stack leaves that stack unchanged. A combined instruction counts as one Push_swap operation.

## Algorithms and complexity

The subject measures sorting complexity by the number of generated Push_swap operations. Internal C comparisons and list traversals are separate from this metric. In the explanations below, `n` is the initial number of elements.

### Initial disorder

Before sorting, the program counts inverted pairs: pairs where an earlier value is greater than a later value.

```text
disorder = inverted_pairs / total_pairs
total_pairs = n * (n - 1) / 2
```

The implementation stores the ratio as an integer scaled by 10,000. Thus, `2000` represents 20% disorder and `5000` represents 50%. Inputs with fewer than two elements have disorder zero. The computation takes O(n²) internal CPU time and O(1) additional space; it generates no stack operations. Rank assignment also takes O(n²) internal CPU time.

### Simple: bubble-sort adaptation

The algorithm compares the top two elements of A, swaps them when necessary and pushes the top element to B. After traversing A, it returns the elements from B to A. It repeats until A is sorted.

Each pass moves a maximum to the end of the traversed region. A pass generates O(n) operations, and at most O(n) passes are needed, giving O(n²) operations in the worst case. This method was selected as a straightforward baseline whose behavior can be explained and compared with the other strategies.

### Medium: indexed sliding window

The window size is approximately `1.5 * ceil(sqrt(n))`. While transferring A to B, the algorithm compares the top index with B's current size:

- Indices at most `size(B)` are pushed to B, followed by a rotation of B.
- Indices at most `size(B) + window` are pushed to B without that rotation.
- Larger indices are rotated within A until they become eligible.

After A is empty, the algorithm repeatedly finds the maximum index in B, brings it to the top using the shorter rotation direction, and pushes it to A. This restores the values in ascending order.

This range-based method was selected to distribute values progressively and reduce movement compared with the simple strategy. The intended target is O(n√n) operations. However, choosing a √n window alone does not prove this bound: a complete argument must bound the total rotations in both distribution and recovery. Without that argument, a conservative upper bound is O(n²) operations. Finding each maximum also requires list traversals, giving O(n²) internal CPU work across the recovery phase.

### Complex: binary LSD radix sort

Radix processes the normalized indices from the least significant bit to the most significant bit. For each bit, it pushes zero-bit elements to B and rotates one-bit elements in A, then returns B to A. This preserves the ordering established by earlier bit passes.

There are O(log n) bits. Each pass emits `n` distribution operations and at most `n` return operations, giving O(n log n) operations. This method was selected for its predictable operation count, simple bit-based logic and independence from the magnitude or sign of the original integers.

### Adaptive selection

| Initial disorder | Current selected method | Subject target |
| --- | --- | --- |
| `< 0.2` | Simple / bubble adaptation | O(n) |
| `>= 0.2` and `< 0.5` | Medium / sliding window | O(n√n) |
| `>= 0.5` | Complex / radix | O(n log n) |

The thresholds follow the regimes specified in the subject. The current design reuses the three explicit strategies: a baseline for low disorder, range-based distribution for medium disorder and radix for high disorder.

**Current limitation:** the low-disorder branch selects an O(n²) method and therefore does not satisfy the subject's O(n) target. A low inversion ratio does not guarantee linear behavior for this bubble implementation. For example, `2 3 ... n 1` has disorder `2/n`, but requires `n - 1` bubble passes. The medium branch also requires the operation-bound justification described above. The current selector must not be described as satisfying all adaptive complexity requirements.

### Space and internal running time

The stack nodes occupy O(n) space. The sorting routines use O(1) additional local state beyond the stacks and recorded moves. The program also records generated moves in a linked list: for `m` emitted operations, total storage is O(n + m), rather than O(n) overall.

Including preprocessing and move recording, the simple and radix implementations have O(n²) internal running-time upper bounds; the medium implementation has a conservative O(n²) bound as well. These CPU bounds are distinct from the emitted-operation bounds required by the subject. Recorded moves can require O(n²) space for the simple method and O(n log n) for radix; the conservative medium bound is O(n²).

## Performance targets

The subject defines the following targets for random inputs. These thresholds are objectives, not measured results for this repository.

| Input size | Minimum requirement | Good performance | Excellent performance |
| --- | --- | --- | --- |
| 100 numbers | < 2,000 operations | < 1,500 operations | < 700 operations |
| 500 numbers | < 12,000 operations | < 8,000 operations | < 5,500 operations |

Correctness and efficiency are separate checks: a valid sequence must sort A and leave B empty, while its operation count determines whether a performance target is met.

## Testing

Useful checks include sorted and reversed inputs, small permutations, random inputs, integer limits, duplicates and invalid tokens. Each explicit strategy and the default adaptive behavior should be checked separately. Benchmark output should be checked independently from standard output.

```sh
./push_swap --complex 3 1 2 | ./checker 3 1 2
./push_swap --complex 3 1 2 | wc -l
./push_swap --bench --complex 3 1 2 > operations.txt 2> benchmark.txt
```

Passing correctness tests or fixed-size performance tests does not by itself establish an asymptotic complexity bound.

## Contributions

- **salegari:** input parsing and validation, bonus input parsing, the simple algorithm, disorder calculation and benchmark mode.
- **marlope3:** stack operations, the medium algorithm, radix sort and development of the bonus checker.
- **Joint work:** adaptive strategy, integration, debugging and testing.

Both contributors must understand and be able to explain all parts of the project.

## Resources

- The provided Push_swap subject: project rules, operation model, strategy requirements and performance targets.
- Thomas H. Cormen et al., *Introduction to Algorithms*: asymptotic analysis and sorting algorithms.
- Donald E. Knuth, *The Art of Computer Programming, Volume 3: Sorting and Searching*: sorting methods and their analysis.
- [NIST Dictionary of Algorithms and Data Structures](https://www.nist.gov/dads): algorithm definitions and terminology.
- [GNU Make manual](https://www.gnu.org/software/make/manual/): build rules and dependencies.
- [Valgrind documentation](https://valgrind.org/docs/manual/): memory-error and leak investigation.

### Use of AI

AI was used to research sorting algorithms and their possible adaptations to Push_swap, to help draft and structure this README, and to assist with tests for checking program behavior. The testing assistance covered ideas for test cases and support with test scripts used to exercise sorting correctness and input handling.
