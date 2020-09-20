#include<stdio.h>
#include<math.h>

int main()
{
	float x1,x2,x3,y1,y2,y3,xf1,xf2,xf3,P1,P2,P3,k1,k2,k3,T,P,f,r1,r2,r3,f1,f2,e1,itr,A1,B1,C1,A2,B2,C2,A3,B3,C3,q,v,l;
	A1=3.97786;
	B1=1064.84;
	C1=-41.136;
	A2=4.00139;
	B2=1170.875;
	C2=-48.833;
	A3=3.9300;
	B3=1182.774;
	C3=-52.532;
	P=1;
	T=330;
	f=100;
	xf1=0.5;
	xf2=0.3;
	xf3=0.2;
	P1=pow(10,(A1-(B1/(C1+T))));
	P2=pow(10,(A2-(B2/(C2+T))));
	P3=pow(10,(A3-(B3/(C3+T))));
	k1=P1/P;
	k2=P2/P;
	k3=P3/P;
	q=0.5;
	for(itr=0;itr<100;itr++)
	{
		v=f*q;
		l=f-v;
		printf("v=%f l=%f\n",v,l);
		x1=xf1/((k1-1)*q+1);
			x2=xf2/((k2-1)*q+1);
				x3=xf3/((k3-1)*q+1);
				f1=x1+x2+x3;
				e1=f1-1;
				if(fabs(e1)<0.00001)
				{
					v=f*q;
					l=f-v;
					y1=x1*k1;
					y2=x2*k2;
					y3=x3*k3;
					printf("v=%f l=%f f=%f y1=%f y2=%f y3=%f x1=%f x2=%f x3=%f",v,l,f,y1,y2,y3,x1,x2,x3);
					break;
				}
				else
				{
					r1=-xf1*(k1-1)/pow(((k1-1)*q+1),2);
					r2=-xf2*(k2-1)/pow(((k2-1)*q+1),2);
					r3=-xf3*(k3-1)/pow(((k3-1)*q+1),2);
					f2=r1+r2+r3;
					q=q-e1/f2;
					
				}
				}
				return 0;
	}
	
