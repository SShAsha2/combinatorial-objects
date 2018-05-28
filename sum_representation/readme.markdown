Представление n в виде суммы положительных слагаемых.
Автор: Матвей Жуков.

OEIS: [A000041](https://oeis.org/A000041) Number of partitions of n (the partition numbers).

Представление в виде суммы положительных слагаемых есть то же самое, что и представление n в виде суммы n неотрицательных слагаемых.

Ссылки:
[MathWorld](http://mathworld.wolfram.com/PartitionFunctionP.html),
[Википедия](https://en.wikipedia.org/wiki/Partition_(number_theory)).


Функция `total`: O(n^(3/2)).

Функция `generate_all`: O(n * answer).

Функция `is_valid`: O(n).

Функция `number_by_object`: O(n).

Функция `object_by_number`: O(n).

Функция `prev`: O(n)

Функция `next`: O(n)