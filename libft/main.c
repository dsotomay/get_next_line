#include <stdio.h>
#include "get_next_line.h"
//#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int main()
{
//	char    *line;
//	int     out;
//	int     p[2];
//	int     fd;
//
//	fd = 1;
//	out = dup(fd);
//	pipe(p);
//
//	dup2(p[1], fd);
//	write(fd, "aaa\nbbb\nccc\nddd", 16);
//	dup2(out, fd);
//	close(p[1]);
//	get_next_line(p[0], &line);
//	printf("%s\n", line);
//	get_next_line(p[0], &line);
//	printf("%s\n", line);
//	get_next_line(p[0], &line);
//	printf("%s\n", line);
//	get_next_line(p[0], &line);
//	printf("%s\n", line);

	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	printf("%s\n", line);
	get_next_line(p[0], &line);
	printf("%s\n", line);
	ret = get_next_line(p[0], &line);
	printf("%s\n", line);

//	char 	*line;
//	int		out;
//	int		p[2];
//	int		fd;
//	int		ret;
//
//	out = dup(1);
//	pipe(p);
//
//	fd = 1;
//	dup2(p[1], fd);
//	write(fd, "abcd\n", 5);
//	close(p[1]);
//	dup2(out, fd);
//	get_next_line(p[0], &line);
//	printf("%s\n", line);
//	mt_assert(strcmp(line, "abcd") == 0);
//	ret = get_next_line(p[0], &line);
//	printf("%s\n", line);
//	mt_assert(ret == 0);
}

