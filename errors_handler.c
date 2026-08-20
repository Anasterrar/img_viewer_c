#include "visual.h"

int	is_ppm_file(char *fileName)
{
	int	i;
	int	j;
	char	extension[5] = ".ppm";

	i = ft_strlen(fileName) - 4;
	j = 0;
	while (fileName[i] || extension[j])
	{
		if (fileName[i] != extension[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	error_input(int argc, char **argv)
{
	int	i;
	int	fd;
	bool 	is_error;
	
	i = 1;
	is_error = false;
	if (argc < 2)
	{	
		fprintf(stderr, ERROR_ARGUMENT_MISSING);
		goto error;
	}
	
	while (i < argc)
	{
		if (!is_ppm_file(argv[i]))
		{
			is_error = true;
			fprintf(stderr, "Error: %s is not a ppm file\n", argv[i]);
			goto pass;
		}
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			is_error = true;
			fprintf(stderr, "Error: %s: no such file\n", argv[i]);
		}
		else
			close(fd);
		pass:
			i++;
	}
	if (is_error)
		goto error;
	return (0);
	error:
		return (1);
}
