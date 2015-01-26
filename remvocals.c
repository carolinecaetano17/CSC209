#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	if(argc != 3){
		printf("ERROR: Invalid number of arguments! %d\n",argc);
		return -1;
	}

	char * fromName = argv[1];
	char * toName = argv[2];
	short *values = malloc(2 * sizeof(int));	
	short newValue;
	printf("%s %s\n",fromName,toName );

	FILE *from = fopen ( fromName,"rb" );
	if (from == NULL){
	    printf("ERROR: Impossible to open files!\n");
  	}

  	FILE *to = fopen ( toName,"wb");
	if (to == NULL){
	    printf("ERROR: Impossible to open files!\n");
  	}

  	void *buffer = malloc(44);

  	fread (buffer,44,1,from);
  	printf("%s\n",(char*)buffer );
  	fwrite ( buffer, 44, 1, to );
  	printf("Wrote %d\n",sizeof(short));

  	while (fgetc(from) != EOF) {
  		//printf("W1\n");
  		fread (values,sizeof(short),2,from);

  		newValue = (values[0] - values[1])/2;
  	
  		printf("BEFORE left: %d right: %d new: %d\n",values[0],values[1],newValue );
  		values[0] = values[1] = newValue;
  		printf("AFTER left: %d right: %d new: %d\n",values[0],values[1],newValue );
  		fwrite ( values,sizeof(short),2, to );
  		
  		
  	}

  	fclose(from);
  	fclose(to);
  	free(buffer);
  	free(values);
  	return 0;
}