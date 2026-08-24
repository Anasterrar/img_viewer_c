#ifndef IMAGE_H
#define IMAGE_H
//STRUCT
typedef struct s_img_data {
    char			*name;
	char			*type;
	char			*comment;
	int             width;
	int             height;
	int             max_value;
	int             pixels_start;
	int             size;
	char			*pixels_buff;
	t_surface		*loaded_img;
	struct s_img_data	*previous;
	struct s_img_data	*next;
}	t_img_data;

//GLOBAL VARIABLE
#define	HEADER_BUFF_SIZE 1000
//FUNCTION

t_img_data      *load_img(char *fileName);
t_img_data      *load_all_img(int argc, char **argv);
void            create_frame(t_img_data **img_data);
//DATA
t_img_data		*create_img_data(char *fileName);
int				get_img_data(t_img_data **img_data, char *header_buff);
int				get_type(t_img_data **img_data, char *header_buff, int *i);
int				get_comment(t_img_data **img_data, char *header_buff, int *i);
int				get_dimension(t_img_data **img_data, char *header_buff, int *i);
int				get_max_value(t_img_data **img_data, char *header_buff, int *i);

void            print_header_img(t_img_data *img_data);
void			free_all_img(t_img_data **img_data);
#endif