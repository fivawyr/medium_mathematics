- "numerically": (physics-) calculations that are done by a computer instead of calculating it with pen and paper (really good examples are solve difficult integrals, nonlineare differential equations or to inverse a 1000 x 1000 matrix)
- also labs and experiements are controlled and runned by computers (data analysis of the results from experiements for detecting minor or really fast issues/bottlenecks and for machine learning, bayesian statistics and arificial intelligents)
- we always have to convert from radiant to degrees, for example if we want to give input for $\theta$, we have to devide multiple with $\pi$ and divide by 180 (degrees) `theta = d*pi/180`
```python
# fibonacci without recursion
f1, f2 = 1, 1 
while f1 <= 1000:
    print(f1)
    f1, f2 = f2, f1 + f2
```
- we can only do calculations with multiple arrays, if we use numpy arrays (regular included arrays in python doesnt support this big advantage in comparision to list):
```python 
from numpy import zeros
a = zeros(4, float)
-> prints [0. 0. 0. 0.]
```
- for two dimensional floating point arrays, we use this syntax:
```
a = zeros([3, 4], float)
-> prints [[0. 0. 0. 0.]
           [0. 0. 0. 0.]
           [0. 0. 0. 0.]
           [0. 0. 0. 0.]
```
- `a = empty(4, float)` for an empty array
- you can also convert an array into a list: 
```python
from numpy import array
list = [1, 3, 5, 6]
a = array(list, float)
```
- ein sehr hoher Anwendungsfall in Computational Physics ist eine andere file mit wichtigen Werten auszulesen und diese in eine Datenstruktur zu speichern. Das kann man zwar mit den eingebauten Funktionen machen, numpy hat aber eine deutlich simplere Version davon:
```
-> txt file mit diesen Inhalt: 
1.0
4.0
-123
10
from numpy import loadtxt
a = loadtxt("values.txt", float)
-> gibt Elemente in einer Liste zurück: [1.0 4.0 -123.0 10.0]
```
- here is also an example how to use operations on whole arrays:
```python
a = array([1, 2, 4, 5], int)
b = 2 * a 
-> [2, 4, 8, 10]

a = array([1, 2, 3, 4], int)
b = array([2, 4, 6, 8], int)
print(a + b)
-> [3 6 9 12]
```
- function to convert polar coordinates to Cartesian coordinates: 
```python
def cartes(r, theta):
    x = r*cos(theta)
    y = r*sin(theta)
    position = [x, y]
    return array(position, float)
```
- Catalan numbers, binomial coefficients, fibonacci are the most famous usecases for recursion
```python
def factorial(n):
    if n == 1: 
        return 1 
    else:
        return n * factorial(n - 1)
```
- 


















