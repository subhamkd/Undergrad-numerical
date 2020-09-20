#include<stdio.h>
#include<math.h>

int main()
{
	float A1,A2,A3,B1,B2,B3,C1,C2,C3,T,P,P1,P2,P3,x1,x2,x3,p1,p2,p3,temp,f1,f2,g1,g2,e1,e2;
	float y1,y2,y3;
	int itr;
	A1=3.97786; //antoine coefficients
	B1=1064.84;
	C1=-41.136;
	A2=4.00139;
	B2=1170.875;
	C2=-48.833;
	A3=3.9300;
	B3=1182.774;
	C3=-52.532;
	g1=300.0; //guess 1
	g2=400.0; //guess 2
	x1=0.5;//mass fraction in liquid
	x2=0.3;
	x3=0.2;
	P=5.0; //pressure
	T=g1;
	P1=pow(10,(A1-(B1/(C1+T))));
	P2=pow(10,(A2-(B2/(C2+T))));
	P3=pow(10,(A3-(B3/(C3+T))));
	p1=x1*P1;
	p2=x2*P2;
	p3=x3*P3;
	f1=p1+p2+p3;
	e1=P-f1;
		for(itr=0;itr<100;itr++)
		{
			T=g2;
			P1=pow(10,(A1-(B1/(C1+T))));
	P2=pow(10,(A2-(B2/(C2+T))));
	P3=pow(10,(A3-(B3/(C3+T))));
	p1=x1*P1;
	p2=x2*P2;
	p3=x3*P3;
	f2=p1+p2+p3;
	e2=P-f2;

	if(fabs(e2)<0.0001)
	{
		y1=(p1/P);
		y2=(p2/P);
		y3=(p3/P);
			printf("bubble point temperature is %f after %d itr \n",g2,itr);
			printf("P1_sat is %f \n",P1);
			printf("P2_sat is %f \n",P2);
			printf("P3_sat is %f \n",P3);
			printf("p1 is %f \n",p1);
				printf("p2 is %f \n",p2);
					printf("p3 is %f \n",p3);
						printf("y1 is %f \n",y1);
							printf("y2 is %f \n",y2);
								printf("y3 is %f \n",y3);
								break;

	}
	else{
		temp=g2-(e2*(g2-g1)/(e2-e1));
			g1=g2;
			e1=e2;
			g2=temp;
		}

	}
return 0;
}
