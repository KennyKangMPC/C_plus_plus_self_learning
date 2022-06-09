import time as tt
import functools

@functools.lru_cache(maxsize=5)
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)

t1 = tt.time()
fib(30)
print("Time taken: {}".format(tt.time() - t1))
# 0.17687273025512695