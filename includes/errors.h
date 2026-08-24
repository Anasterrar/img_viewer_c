#ifndef ERROR_H
#define ERROR_H
#define ERROR_ARGUMENT_MISSING "Error: no argument provided\n"
int     error_input(int argc, char **argv);
//ERROR IMG
int	    is_ppm_file(char *fileName);
int	    error_input_img(int argc, char **argv);

#endif