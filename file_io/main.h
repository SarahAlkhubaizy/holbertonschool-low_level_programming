#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void open_files(char *file_from, char *file_to, int *fd_from, int *fd_to);
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to);
void close_files(int fd_from, int fd_to);
#endif /* MAIN_H */
