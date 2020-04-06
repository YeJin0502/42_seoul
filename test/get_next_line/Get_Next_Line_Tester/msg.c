#include<stdio.h>
	int main(int argc,char **argv){printf("\e[1;%sm\t%s\n\e[0m",argv[1],argv[2]);}
