#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*int main(int ac, char **av)
{
	int fd;
	int res;
	char *line;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while ((res = get_next_line(fd, &line)))
	{
		ft_putnbr(res);
		ft_putchar(' ');
		ft_putendl(line);
	}
	ft_putnbr(res);
	return (0);
*/

/*int		main()
{
	int		fd;
	char	*line;
	//char no;
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);

	ft_putendl_fd(line, 1);
	ft_putnbr(fd);

	close(fd);
	return (0);
}*/


/*int    main()
{
    int fd;
    char *line;
    int no;
    int i;

    fd = open("text", O_RDONLY);
    no = get_next_line(fd, &line);
    i = 0;
    //while (line[i])
    //{
        printf("%d\n", no);    i++;
//    }
    close(fd);
    return (0);
}*/
int	main()
{
	char *str;
	int fd = open("texttxt", O_RDONLY);
	int r;
    close(fd);
	while((r = get_next_line(fd, &str)) > 0)
	{
		ft_putnbr(r);
	}
	//close(fd);
	ft_putnbr(r);
	return (0);
}
