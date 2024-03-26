from sympy import bell
from sympy.functions.combinatorial.numbers import stirling
from sympy.utilities.iterables import multiset_partitions

def partitions(n, k):
    return list(multiset_partitions(list(range(1, n + 1)), k))

def bell_number(n):
    return bell(n)

n = 4
for k in range(1, n + 1):
    print(f"Partitions of [{n}] into {k} parts:")
    for partition in partitions(n, k):
        print(partition)

print(f"The 4th Bell number is: {bell_number(4)}")