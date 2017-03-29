#include <stdio.h>
	#include <stdlib.h>
	#include <sys/time.h>
	
	#define R 1
	#define N 60
	#define M 120
	
	//sunarthsh gia thn metrhsh tou xronou
	void get_walltime(double *wct)//deiktis
	{
		struct timeval tp;
		gettimeofday(&tp,NULL);
		*wct=(double)(tp.tv_sec+tp.tv_usec/1000000.0);
	}
	
	int main()
	{
	float *x,*y;
	int i,j;
	double tb,tf,mflops;//tb: time begin, tf: time finished
	const float K0=0.5, K1=0.5, K2=0.5, K3=0.5, K4=5.0, K5=0.5, K6=0.5, K7=0.5, K8=0.5;//co-efficient
	
	//katanomh systoixies kai elegxos
	x = (float *)malloc(N*M*sizeof(float));
	if (x==NULL) exit(1);
	y = (float *)malloc(N*M*sizeof(float));
	if (y==NULL)
	{
		free(x);
		exit(1);
	}
	
	//epanafora twn pinakwn(cache warm-up)
	
	for (i=0;i<N*M;i++)
	{
		x[i]=0.0; y[i]=0.0;
		
	}
	
	for (i=1;i<N-1;i++)		
	{
		for (j=1;j<M-1;j++)
		{
			*(x+((i*M)+j))=rand()+0.0;//tyxaies times float gia eisodo eikonas
		}
	
	}
	
	
	
	
		
		
	
	
	get_walltime(&tb);//pairnei thn timh ekkinhshs
	
	//load code
	for (i=1;i<N-1;i++)//eisodos eikonas sarwshs xrhsimopoiwntas I kai j ektos anw kai katw orio
			
	{
		for (j=1;j<M-1;j++)
		{
			y[i*M+j]=K0*x[(i-1)*M+(j-1)]+K1*x[(i-1)*M+j]+K2*x[(i-1)*M+(j+1)]+K3*x[i*M+(j-1)]+K4*x[i*M+j]+K5*x[i*M+(j+1)]+K6*x[(i+1)*M+(j-1)]+K7*x[(i+1)*M+j]+K8*x[(i+1)*M+(j+1)];
			
		}
	}
	
	get_walltime(&tf);//o xronos lhxhs
	
	
	
	
	
	
	  
	
	mflops = (M*R*2.0)/((tf-tb)*1e6);
	printf("MFLOPS/sec = %f\n",mflops);
	  
	//apeleytherwsh mnhmhs pou xhsimopoieitai apo tous pinakes
	free(x);
	free(y);
	
	return 0;
	}

