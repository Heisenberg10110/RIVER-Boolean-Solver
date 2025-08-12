# RIVER Boolean Solver

**RIVER Boolean Solver** is a heuristic local search tool to check if multiple Boolean expressions can be satisfied and find a valid assignment. It scores variables by participation and polarity balance, updates only unsatisfied clauses, and uses random flips, greatly accelerating Boolean solving.

## Highlights
- **Heuristic variable scoring** based on participation frequency and polarity balance  
- **Incremental score updates** only for unsatisfied clauses  
- **Random flips** to escape local optima  

## Methodology
1. **Preprocessing** – Scan all expressions to gather statistics for each variable.  
2. **Initialization** – Assign values to variables in descending score order.  
3. **Iteration** – Maintain a list of unsatisfied clauses, choose one, flip the best variable.  
4. **Random Perturbation** – Occasionally flip a random variable to avoid local minima.  

## Example
**Input**
```text
(X1 | ~X2) & (X3) = True
(~X1 | X2 | ~X3) = True
```
**Output**
```
X1 = 1; X2 = 0; X3 = 1
```
## Implementation Details

- **Language**: C++   
- **Performance**: With vector-based optimization, the solver runs in fractions of a second on course benchmarks, **significantly faster than most algorithms of classmates**.
