#include <stdio.h>

int main(int argc, char *argv[])
{
   int c;
   FILE *fp1, *fp2;

    if (    ) {
		fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
		return 1;
    }

	fp1 = fopen(    ,  );
	if (fp1 == NULL) {
		fprintf(stderr, "file %s open error\n", argv[1]);
		return 2;
	}

	fp2 = fopen(     ,  );
	while (              )
		fputc(   ,    );

	fclose(fp1);
	fclose(fp2);

	return 0;
}

