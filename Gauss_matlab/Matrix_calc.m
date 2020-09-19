prompt = 'enter the number of equations';
p=input(prompt);
a=zeros(p);
b=zeros(p,1);
qq='Enter 1 for Gauss elimination and 2 for Gauss-Jordan';
q=input(qq);
for i=1:p
    for j=1:p
        prompt2='enter the elements of the coeffcient matrix, row-wise';
        a(i,j)=input(prompt2);
    end
end
for k=1:p
    prompt3='enter the elements on the RHS of the set of equations';
    b(k,1)=input(prompt3);
end
a
b
if q==1
Gauss(a,b)
else
    Gauss_Jordan(a,b)
end