//C program to determine the inlet conc of component b in a three stage CSTR system

#include<stdio.h>
#include<math.h>
int main()
{
	double caf,cbf,va,vb,v,k,temp,g1,g2,f1,f2,e1,e2,ca1,ca2,cb1,cb2,ca3,cb3,v3,x;
	int itr;
	caf=1.5;
	cbf=1.5;
	va=36;
	vb=36;
	v=10;
	k=16.88;
    g1=-0.50;
    g2=5.0;
	cb1=g1;
	ca1=caf*va/(va+k*cb1*v);
	cb2=cb1*(vb+k*ca1*v)/vb;
	ca2=ca1*va/(va+k*v*cb2);
	cb3=(vb*cb2+k*cb2*ca2*v)/vb;
	ca3=ca2*va/(va+k*v*cb3);
	f1=(v*cb3+k*cb3*ca3*v)/vb;
	e1=1.5-f1;
	for(itr=0;itr<1000;itr++)
	{
	    cb1=g2;
		ca1=caf*va/(va+k*cb1*v);
	    cb2=cb1*(vb+k*ca1*v)/vb;
	    ca2=ca1*va/(va+k*v*cb2);
	    cb3=(vb*cb2+k*cb2*ca2*v)/vb;
	    ca3=ca2*va/(va+k*v*cb3);
	    f2=(v*cb3+k*cb3*ca3*v)/vb;
		e2=1.5-f2;
		if(fabs(e2)<=0.00001)
		{
			printf("\n the solution %f is reached after %d iterations",g2,itr);
			break;
		}
		else
		{
			temp=g2-e2*(g2-g1)/(e2-e1);
			g1=g2;
			e1=e2;
			g2=temp;
		}
	}
return 0;
}
