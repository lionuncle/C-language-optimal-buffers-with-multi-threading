#include <stdio.h>
#include <stdlib.h>
void displayTheValueOfBuffer(char* buffer,int totalValues){
	int i;
	printf("\n");
	for(i=0;i<totalValues;i++){
		printf("%c",buffer[i]);
	}
}
void fillBufferFromFile(char* buffer,int totalValues,FILE* fptr){
	int i;
	for(i=0;i<totalValues;i++){
		buffer[i] = fgetc(fptr);
	}
	printf("\\\\\\\\\\\\\\\\\\\\\\BUFFER FILLED\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
}
int main(){
	FILE *fptr = fopen("compiler.txt","r");
	int bufferSize= 10;
	char* buffer1;
	char* buffer2;
	char readChar;
	if (fptr == NULL){ printf("File opening error \n");exit(0); }
    buffer1 = (char*) calloc(bufferSize/(sizeof(char)),sizeof(char));
	buffer2 = (char*) calloc(bufferSize/(sizeof(char)),sizeof(char));
	fillBufferFromFile(buffer1,(bufferSize/(sizeof(char))),fptr);
	fillBufferFromFile(buffer2,(bufferSize/(sizeof(char))),fptr);
	displayTheValueOfBuffer(buffer1,(bufferSize/(sizeof(char))));
	displayTheValueOfBuffer(buffer2,(bufferSize/(sizeof(char))));
	fillBufferFromFile(buffer1,(bufferSize/(sizeof(char))),fptr);
	displayTheValueOfBuffer(buffer1,(bufferSize/(sizeof(char)))); 
	    
    fclose(fptr);
	
}
