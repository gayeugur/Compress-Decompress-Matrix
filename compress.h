#ifndef compress
#define compress
#define R 6
#define C 6

void compress_CRS(int **, int *, int *, int *);
void compress_CCS(int **, int *, int *, int *);
void compress_IJ(int**, int *, int *, int *);

int **decompress_CRS(int*, int *, int *);
int **decompress_CCS(int *, int *, int *);


#endif
