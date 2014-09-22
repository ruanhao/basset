/* ==================== Buffer ==================== */

#include <stdio.h>
void setbuf(FILE *restrict fp, char *restrict buf);
/* To enable buffering, buf must point to a buffer of length BUFSIZ, a constant defined in <stdio.h>
 * To disable buffering, we set buf to NULL */
int setvbuf(FILE *restrict fp, char *restrict buf, int mode, size_t size); /* mode :: [_IOFBF, _IOLBF, _IONBF] */
/* Both Returns: 0 if OK, nonzero on error */






/* ==================== Open Stream ==================== */

FILE *fopen(const char *restrict pathname, const char *restrict type);
FILE *freopen(const char *restrict pathname, const char *restrict type, FILE *restrict fp);
/* freopen is typically used to open a specified file as one of the predefined streams:
 * standard input, standard output, or standard error */
FILE *fdopen(int filedes, const char *type);
/* fdopen is often used with descriptors that are returned by the functions that create
 * pipes and network communication channels */
/* All three return: file pointer if OK, NULLon error */

/*
 * The type argument for opening a standard I/O stream:
 * Type       |  Description
 * -----------|----------------------------------------------------------------
 * r/rb       |  open for reading
 * -----------|----------------------------------------------------------------
 * w/wb       |  truncate to 0 length or create for writing
 * -----------|----------------------------------------------------------------
 * a/ab       |  append; open for writing at end of file, or create for writing
 * -----------|----------------------------------------------------------------
 * r+/r+b/rb+ |  open for reading and writing
 * -----------|----------------------------------------------------------------
 * w+/w+b/wb+ |  truncate to 0 length or create for reading and writing
 * -----------|----------------------------------------------------------------
 * a+/a+b/ab+ |  open or create for reading and writing at end of file
 */

/*
 * You can also append the character ‘x’ after any of the strings in the table above.
 * This character causes fopen to fail rather than opening the file
 * if the file already exists.
 * If you append ‘x’ to any of the arguments above,
 * you are guaranteed not to clobber (that is,accidentally destroy)
 * any file you attempt to open.
 */

int fclose(FILE *fp);
/* Returns: 0 if OK, EOF on error */

int fflush(FILE *fp);
/* if fp is NULL, this function causes all output streams to be flushed */
/* Returns: 0 if OK, EOF on error */







/* ==================== Read & Write Stream ==================== */

/* read and write one character at a time */

int getc(FILE *fp);  /* can be implemented as a macro */
int fgetc(FILE *fp);
int getchar(void);
/* All three return: next character if OK, EOF on end of file or error */
/* Note that these functions return the same value whether an error occurs or the end of file is reached.
 * To distinguish between the two, we must call either ferror or feof */
int ferror(FILE *fp);
int feof(FILE *fp);
/* Both return: nonzero (true) if condition is true, 0 (false) otherwise */

/* error flag and end-of-file flag can be cleared by calling clearerr */
void clearerr(FILE *fp);

int ungetc(int c, FILE *fp);
/* Returns: c if OK, EOF on error */

int putc(int c, FILE *fp);  /* can be implemented as a macro */
int fputc(int c, FILE *fp);
int putchar(int c);
/* All three return: c if OK, EOF on error */




/* read and write one line at a time */

char *fgets(char *restrict buf, int n, FILE *restrict fp); /* reads up through the next newline (Deprecated) */
char *gets(char *buf); // Deprecated
/* Both return: buf if OK, NULL on end of file or error */

int fputs(const char *restrict str, FILE *restrict fp); /* writes the null-terminated string to the specifiedstream */
int puts(const char *str);
/* Both return: non-negative value if OK, EOF on error */




/* direct I/O */

size_t fread(void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);
size_t fwrite(const void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);
/* Both return: number of objects read or written */
/* both fread and fwrite return the number of objects read or written
 * for read case:  this number can be less than nobj if an error occurs or if the end of file is encountered
 *                 in this case ferror or feof must be called
 * for write case: if the return value is less than the requested nobj, an error has occurred
 */








/* ==================== Locate Stream ==================== */

long ftell(FILE *fp);
/* Returns: current file position indicator if OK, –1L on error */
int fseek(FILE *fp, long offset, int whence); /* whence :: [SEEK_SET, SEEK_CUR, SEEK_END] */
/* Returns: 0 if OK, nonzero on error */

void rewind(FILE *fp);

int fgetpos(FILE *restrict fp, fpos_t *restrict pos);
int fsetpos(FILE *fp, const fpos_t *pos);
/* Both return: 0 if OK, nonzero on error */








/* ==================== I/O Format ==================== */

int printf(const char *restrict format, ...);
int fprintf(FILE *restrict fp, const char *restrictformat, ...);
/* Both return: number of characters output if OK, negative value if output error */

#include <stdio.h>
int sprintf(char *restrict buf, const char *restrict format, ...);
int snprintf(char *restrict buf, size_t n, const char *restrict format, ...);
/* Both return: number of characters stored in array if OK, negative value if encoding error */

int scanf(const char *restrict format, ...); // Deprecated
int fscanf(FILE *restrict fp, const char *restrict format, ...);
int sscanf(const char *restrict buf, const char *restrict format, ...);
/* All three return: number of input items assigned, EOF if input error or end of file before any conversion */









/* ==================== Misc ==================== */

int fileno(FILE *fp);
/* Returns: the file descriptor associated with the stream */

#ifdef _GNU_SOURCE
int asprintf(char **strp, const char *fmt, ...); // more safer than sprintf
/* Returns the number of characters allocated to the buffer,
 * or a negative value if an error occurred */
#endif

ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/* Both returns the number of characters read, or -1 on failure */
/* preferred method for reading lines of text from a stream, including standard input */
/* pointer to the block of memory allocated for getline is merely a suggestion.
 * getline function will automatically enlarge the block of memory as needed,
 * via the realloc function, so there is never a shortage of space */
