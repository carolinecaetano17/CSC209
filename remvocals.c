#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	if(argc != 3){
		printf("ERROR: Invalid number of arguments! %d\n",argc);
		return -1;
	}

	char * fromName = argv[1];
	char * toName = argv[2];
	short int left,right;
	short int newValue;

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
  	printf("Wrote %d\n",sizeof(short int));

  	while (fgetc(from) != EOF) {
  	
  		//printf("W1\n");
  		fread (&left,sizeof(short int),1,from);
  		fread (&right,sizeof(short int),1,from);

  		newValue = (left - right)/2;
  	
  		//printf("BEFORE left: %d right: %d new: %d\n",left,right,newValue );
  		
  		//printf("AFTER left: %d right: %d new: %d\n",newValue,values[1],newValue );
  		fwrite ( &newValue,sizeof(short int),1, to );
  		fwrite ( &newValue,sizeof(short int),1, to );
  		
  		
  	}

  	fclose(from);
  	fclose(to);
  	free(buffer);
  	//free(values);
  	return 0;
}