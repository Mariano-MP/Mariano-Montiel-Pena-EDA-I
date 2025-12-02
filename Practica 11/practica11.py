def fibonacci(n, memo={}):
    if n <= 1:
        return n
    if n in memo:
        return memo[n]
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    return memo[n]

posiciones = [7, 21, 40, 71, 94]

for p in posiciones:
    print(f"Fibonacci({p}) = {fibonacci(p)}")
