#include<stdio.h>
#include<stdlib.h>
int main(){
  	FILE *input;
  	FILE *output;
	char infile[24];
	char outfile[24];
	char buffer;
	printf("enter the input file name:");
	scanf("%s",infile);
	printf("enter the output file name:");
	scanf("%s",outfile);
	if((input=fopen(infile,"r"))==NULL){
		printf("input file cannot open,program terminated");
	return 1;
}
	if((output=fopen(outfile,"r"))==NULL){
	output=fopen(outfile,"w");
}
	else{
		printf("output file already existed,program terminated");
		return 2;
}
	while(!feof(input)){
		fread(&buffer,sizeof(char),1,input);
		fwrite(&buffer,sizeof(char),1,output);
}
	printf("copy completed");
	return 0;
}
