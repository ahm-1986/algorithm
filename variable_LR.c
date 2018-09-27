/*
This algorithm does vriable left rotation on variable register size (up to 32 bit) 

R: register size
n: value
d: rotation constant

*/


#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;


u32 leftRotate(u32 R,u32 n, u32 d)
{

	u32 mask= 0x1;
	u32 lmask= (mask<<d)-1;
	u32 fmask= (mask<<R)-1;
	u32 lmaskloc= lmask<<R;  //location of the mask;
	u32 S0= n<<d;
	u32 S0loc= S0&lmaskloc;
	
	u32 S1= S0loc >> (R) ;

   return (((S0)| (S1))&(fmask));
}

int main(int argc, char **argv){
	unsigned int  x =2;
	unsigned int  rv =0;
	if(argc==2) x=atoi(argv[1]);
	else if(argc==3) {x=atoi(argv[1]); rv=atoi(argv[2]);}
	
	
	for(int i=0;i<(1<<x);i++){


		printf("%x-->%x\n",i,leftRotate(x,i,rv));
	}
	


	

	return 0;
}