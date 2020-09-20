#include<stdio.h>
#include<math.h>
#define pi 3.1416
int main()
{
	float th1,tc1,th2,tc2,th,tc,m=3,cph=1,cpc=1,u=0.5,d=0.5,x=0.1,dx=0.1,th0,tc0;
	FILE *fp;
	int i,j,k;
	fp=fopen("heat.dat","w");
	th0=60;
	tc0=25;
	th=th0;
	tc=tc0;
	for(j=1;j<100;j++)
	{
		x=x+dx;
			th=th0+((tc-th)*u*pi*d/(m*cph))*dx;
			tc=tc0+((th-tc)*u*pi*d/(m*cpc))*dx;
		th0=th;
		tc0=tc;
		if(j%10==0)
		{
		printf("\n %f %f %f",x,tc,th);
	    fprintf(fp,"\n %f %f %f",x,tc,th);
	    }
	}
	fclose(fp);
}
