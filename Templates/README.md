# Operator Overloading
* Define a class `BigInteger` that stores arbitrarily large integers
by keeping their digits in a vector<int>. Supply a constructor `BigInteger(string)` that  reads a sequence of digits from a string. Overload the +, -, and * operators to add, subtract, and multiply the digit sequences.
Overload the << operator to send the big integer to a stream. For example,

```cpp
BigInteger a("123456789");
BigInteger b("987654321");
cout << a * b;
```
prints 121932631112635269.

* Due: 3/28/2019