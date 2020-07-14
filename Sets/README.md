# Exercise P13.3
##### Sieve of Eratosthenes
* Implement the *sieve of Eratosthenes*: a function for computing prime numbers, known to the ancient Greeks. Choose an
integer *n*. This function will compute all prime numbers up to *n*. First insert all numbers from 1 to *n* into a set.
Then erase all multiples of 2 (except 2); that is, 4, 6, 8, 10, 12, .... Erase all multiples of 3, that is, 6, 9, 12, 15, .... Go up to √*n*. The remaining numbers are all primes.