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
also try with lambda:=3.1 or 3 or 3.5 or 3.55
solve(lambda*x(1-x)=x,x); evalf(2/3);
x:=0.7
for i from 1 to 200 do x:=lambda*x*(1-x); f[i]:=x: od:
points:=[[n,f[n]]$n=1..1200]:
pointplot(points,symbol=circle);
# this is chaos...

#Problem 4 and 5
restart;
with(plots):
lambda:=3.8
solve(lambda*x(1-x)=x,x); evalf(2/3);
x:=0.7
for i from 1 to 200 do x:=lambda*x*(1-x); f[i]:=x: od:
points:=[[n,f[n]]$n=1..1200]:
pointplot(points,symbol=circle);
# this is chaos...

restart:  
  
lambda := 3.8:  
  
# find fixed points (symbolic)  
solve(lambda*x*(1-x)=x, x);  
  
# iteration  
x := 0.7:  
  
for i from 1 to 200 do  
x := lambda*x*(1-x);  
f[i] := x;  
od:  
  
# build points  
points := [seq([n, f[n]], n=1..200)]:  
  
with(plots):  
pointplot(points);

```


```
#Problem 3:
restart;
with(plots):
x:=0.7
for i from 1 to 200 do x:=2*x*(1-x); f[i]:=x: od:
points:=[[n,f[n]]$n=1..200]:
pointplot(points, symbol=circle);


#Problem 4 and 5:
restart:
with(plots):
lambda:=4;
solve(lambda*x*(1-x)=x,x); evalf(2/3);
x:=0.7
for i from 1 to 1200 do x:=lambda*x*(1-x); f[i]:=x: od:
points:=[[n,f[n]]$n=1..1200]:
pointplot(points,symbol=circle);

```