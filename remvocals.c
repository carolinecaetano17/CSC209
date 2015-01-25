#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	if(argc != 3){
		printf("ERROR: Invalid number of arguments! %d\n",argc);
		return -1;
	}

	char * fromName = argv[0];
	char * toName = argv[1];
	int *values = malloc(2 * sizeof(int));	
	int newValue;

	FILE *from = fopen ( fromName,"rb" );
	if (from == NULL){
	    printf("ERROR: Impossible to open files!\n");
  	}

  	FILE *to = fopen ( toName,"wb" );
	if (to == NULL){
	    printf("ERROR: Impossible to open files!\n");
  	}

  	void *buffer = malloc(44);

  	fread (buffer,1,44,from);
  	fwrite ( buffer, 1, 44, to );

  	while (fgetc(from) != EOF) {
  		fread (values,sizeof(int),2,from);
  		newValue = 0;
  		newValue += values[0];
  		newValue += values[1];
  		newValue = newValue/2;
  		values[0] = values[1] = newValue;
  		fwrite ( values,sizeof(int),2, to );
  		
  	}

  	fclose(from);
  	fclose(to);
  	free(buffer);
  	free(values);
}