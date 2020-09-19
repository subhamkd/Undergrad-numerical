function [x] = Gauss(a,y)
%GAUSS elimination method for solution of a set linear equations
a=[a y]; %a will be the new augmented matrix
[m,n]=size(a); 
for j=1:m-1 %for changing the pivot elements
    for z=2:m 
        if a(j,j)==0
            t=a(1,:);a(1,:)=a(z,:); %checking if any pivot element is 0 
            a(z,:)=t;
        end
    end
    for i=j+1:m
        a(i,:)=a(i,:)-a(j,:)*(a(i,j)/a(j,j));
    end
end
a %the upper triangular matrix
  x(m) = a(m,n)/a(m,n-1);
       for i = m-1:-1:1
           s=0;
         for j=i+1:m
           s=s+a(i,j)*x(j);
         end
        x(i) = (a(i,n)-s)/a(i,i);
      end
end
