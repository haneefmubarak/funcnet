#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct byte {
	unsigned char A;
	unsigned char B;
	unsigned char C;
	unsigned char D;
	unsigned char E;
	unsigned char F;
	unsigned char G;
	unsigned char H;
};

int main (int argc, char *argv[]) {
	if (argc != 2) {
		puts("Funcnet takes exactly one argument: filename.");
		exit(1);
	}

	struct byte bitnet[512];

	struct stat st;
	stat(argv[1], &st);
	//printf("%i\n", st.st_size);

	unsigned char *code = (unsigned char*) malloc(sizeof(unsigned char) * st.st_size);
	if (code == NULL) { puts("Could not allocate sufficient memory."); exit(2); }

	FILE *infile;
	infile = fopen(argv[1], "r");
	if (infile == NULL) { puts("Could not open file for reading."); exit(3); }

	fread(code, sizeof(unsigned char), st.st_size, infile);
	fclose(infile);

	printf("/n %s", code);
	putchar(0xB);

	// Cleanup
	free(code);
	return 0;
}
