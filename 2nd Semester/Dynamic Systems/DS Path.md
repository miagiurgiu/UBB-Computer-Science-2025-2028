https://math.ubbcluj.ro/~abuica/dynsys.htm - website

## Lab 1 - 25 feb 2026
Setup Maple, lab1 exercises
HW: finish lab1 exercises

## Lab 5 - 29 apr 2026


```
#Problem 3

restart;
with(plots);
x:=0.7
for i from 1 to 200 do x:=2*x(1-x); f[i]:=x: od:


#Problem 4 and 5
restart;
with(plots):
lambda:=4
solve(lambda*x(1-x)=x,x); evalf(2/3);
x:=0.7
for i from 1 to 200 do x:=lambda*x*(1-x); f[i]:=x: od:
points

```