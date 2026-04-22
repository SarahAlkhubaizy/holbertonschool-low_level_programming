#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * open_files - opens file_from and file_to
 * @file_from: name of file to read from
 * @file_to: name of file to write to
 * @fd_from: pointer to store fd of file_from
 * @fd_to: pointer to store fd of file_to
 */
void open_files(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
}

/**
 * copy_content - copies content from fd_from to fd_to
 * @fd_from: file descriptor to read from
 * @fd_to: file descriptor to write to
 * @file_from: name of file_from for error message
 * @file_to: name of file_to for error message
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buf[1024];
	ssize_t r;
	ssize_t w;

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * close_files - closes fd_from and fd_to
 * @fd_from: file descriptor to close
 * @fd_to: file descriptor to close
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from;
	int fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	open_files(av[1], av[2], &fd_from, &fd_to);
	copy_content(fd_from, fd_to, av[1], av[2]);
	close_files(fd_from, fd_to);
	return (0);
}
