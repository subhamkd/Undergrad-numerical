#include<stdio.h>
#include<math.h>
int main()
{
	int nt,nt_max=1000;
	FILE *fp;
	fp=fopen("CSTR_holdup_nonisothermal_data.dat","w");
	float t=0.0,dt=0.01,h,h0=0.0579,k,k0=147.97;
	h=h0;
	k=k0;
	for(nt=0;nt<nt_max;nt++)
	{
		t=t+dt;
		h=h0+dt*(0.6-h-pow(10,10)*exp(-8830.1/(k+273.15))*h);
		k=k0+dt*(90-k+1.3*pow(10,12)*exp(-8830.1/(k+273.15))*h);
		h0=h;
		k0=k;
		if(nt%10==0)
		{
		printf("\n %f %f %f",t,h,k);
	    fprintf(fp,"\n %f %f %f",t,h,k);
	    }
	}
	fclose(fp);
}
