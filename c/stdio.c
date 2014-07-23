#include <stdio.h>
/* Returns: 0 if OK, nonzero on error */
void setbuf(FILE *restrict fp, char *restrict buf); /* To enable buffering, buf must point to a buffer of length BUFSIZ, a constant defined in <stdio.h>
                                                       To disable buffering, we set buf to NULL
                                                     */
int setvbuf(FILE *restrict fp, char *restrict buf, int mode, size_t size); /* mode :: [_IOFBF, _IOLBF, _IONBF] */

/* Returns: 0 if OK, EOF on error */
int fflush(FILE *fp); /* If fp is NULL, this function causes all output streams to be flushed */

/* All three return: file pointer if OK, NULLon error */
FILE *fopen(const char *restrict pathname, const char *restrict type);
FILE *freopen(const char *restrict pathname, const char *restrict type, FILE *restrict fp); /* This function is typically used to open a specified file as one of the predefined streams:
                                                                                               standard input, standard output, or standard error */
FILE *fdopen(int filedes, const char *type); /* This function is often used with descriptors that are returned by the functions that create
                                                pipes and network communication channels */

/* The type argument for opening a standard I/O stream:
   Type        Description
   r/rb        open for reading
   w/wb        truncate to 0 length or create for writing
   a/ab        append; open for writing at end of file, or create for writing
   r+/r+b/rb+  open for reading and writing
   w+/w+b/wb+  truncate to 0 length or create for reading and writing
   a+/a+b/ab+  open or create for reading and writing at end of file
*/

/*
 * When a file is opened for reading and writing, the following restrictions apply:
 * 1. Output cannot be directly followed by input withoutan intervening fflush, fseek, fsetpos,or rewind
 * 2. Input cannot be directly followed by output withoutan intervening fseek, fsetpos,or rewind,
 *    or an input operation that encounters an end of file
*/

/* Returns: 0 if OK, EOF on error */
int fclose(FILE *fp);

/* Three functions allow us to read one character at atime */
/* All three return: next character if OK, EOF on end of file or error */
int getc(FILE *fp); /* can be implemented as a macro */
int fgetc(FILE *fp);
int getchar(void);
/* Note that these functions return the same value whether an error occurs or the end of file is reached.
   To distinguish between the two, we must call either ferror or feof */
/* Both return: nonzero (true) if condition is true, 0 (false) otherwise */
int ferror(FILE *fp);
int feof(FILE *fp);

/* error flag and end-of-file flag can be cleared by calling clearerr */
void clearerr(FILE *fp);

/* Returns: c if OK, EOF on error */
int ungetc(int c, FILE *fp);


/* All three return: c if OK, EOF on error */
int putc(int c, FILE *fp); /* can be implemented as a macro */
int fputc(int c, FILE *fp);
int putchar(int c);

/* Both return: buf if OK, NULL on end of file or error */
char *fgets(char *restrict buf, int n, FILE *restrict fp); /* reads up through the next newline */
char *gets(char *buf);

/* Both return: non-negative value if OK, EOF on error */
int fputs(const char *restrict str, FILE *restrict fp); /* writes the null-terminated string to the specifiedstream */
int puts(const char *str);

/* Both return: number of objects read or written */
size_t fread(void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);
size_t fwrite(const void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);
/* Both fread and fwrite return the number of objects read or written.
 * For the read case, this number can be less than nobj if an error occurs or if the end of file is encountered.
 * In this case ferror or feof must be called.
 * For the write case, if the return value is less than the requested nobj, an error has occurred.
 */

/* Returns: current file position indicator if OK, –1L on error */
long ftell(FILE *fp);
/* Returns: 0 if OK, nonzero on error */
int fseek(FILE *fp, long offset, int whence); /* whence :: [SEEK_SET, SEEK_CUR, SEEK_END] */

void rewind(FILE *fp);

/* Both return: 0 if OK, nonzero on error */
int fgetpos(FILE *restrict fp, fpos_t *restrict pos);
int fsetpos(FILE *fp, const fpos_t *pos);
