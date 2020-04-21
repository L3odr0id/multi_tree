# Multi tree
C++ code that creates very simple tree of different objects. Download and modify the code!
 
 
### Input: 
```
fist line : <name for root object>
next lines: <name of object to connect> <name of new object> <num of class (2,3,4)> <data> 
last line: endtree
```
 
  
#### Input example: 
```
root
root obj1 3 1
root obj2 2 10
obj1 lol 4 -3
endtree
```
 
#### Tree structure:
```
root
|
|-obj1
| |-lol
|
|-obj2
```
 
  
Object is ready, when data > 0.

#### Output example:
```
The object root is ready
The object obj1 is ready
The object lol is not ready
The object obj2 is ready
```
