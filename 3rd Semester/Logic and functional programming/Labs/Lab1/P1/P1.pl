% lowest common multiple of a list (integer numbers)

% gcd of two numbers
% gcd(a,b) = a, b=0
%            gcd(a,a mod b), otherwise
% flow model gcd(A,B,Res)=(i,i,o)
gcd(A,B,Res):- B=:=0, Res is A.
gcd(A,B,Res):- B=\=0, A1 is A mod B, gcd(B,A1,Res).

% lcm of two numbers
% lcm2(a,b)=0, a=0 or b=0
%.            (a*b)/gcd(a,b), otherwise
% flow model lcm2(A,B,Res)=(i,i,o)
lcm2(A,B,Res):- (A=:=0 ; B=:=0), Res is 0.
lcm2(A,B,Res):- A=\=0 , B=\=0, gcd(A,B,Gcd), Res is (A*B) div Gcd.

% lowest common multiple of a list (integer numbers)
% lcm(l1...ln,C)=C, n=0
%                  lcm(l2...ln,lcm2(C,|l1|)), otherwise
% flow model lcm(L,C,Res)=(i,i,0)
lcm([],C,C). % base case ([] already means n=0)
lcm([H|T],C,Res):- H1 is abs(H), lcm2(C,H1,C1), lcm(T,C1,Res).
 % "otherwise" case ([H|T] already means n!=0)
 % res gets assigned through actually calling the recursive function, you will never see Res is ... unless it is in a base case

% WRAPPER (i,o)
lcmList(L,Res):- lcm(L,1,Res).

% insert v after 1st, 2nd, 4th, 8th elem in a list
% insert(l1...ln,v,p,k)=[], n=0
%                       l1 U v U insert(l2...ln,v,p+1,2*k), p=k
%                       l1 U insert(l2...ln,v,p+1,k), p!=k
% flow model: insert(L,V,P,K,R)=(i,i,i,i,o)
insert([],_,_,_,[]).
insert([H|T],V,P,K,[H,V|R]):- P=:=K, P1 is P+1, K1 is K*2, insert(T,V,P1,K1,R).
insert([H|T],V,P,K,[H|R]):- P=\=K, P1 is P+1, insert(T,V,P1,K,R).

% WRAPPER (i,i,o)
addAfter(L,V,R):- insert(L,V,1,1,R).