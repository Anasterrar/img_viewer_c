#include "visual.h"

#define RESET   "\033[0m"
#define BLUE    "\033[38;5;39m"
#define BOLD    "\033[1m"
#define CYAN    "\033[38;5;51m"

void    print_header_img(t_img_data *img_data)
{
	system("clear");
	printf("\n");
        printf(BLUE "╔══════════════════════════════════════════════╗" RESET "\n");
        printf(BLUE "║" RESET "                                              " BLUE "║" RESET "\n");
        printf(BLUE "║" RESET "              " BOLD CYAN "✦  IMAGE VIEWE  ✦" RESET
                "             " BLUE " ║" RESET "\n\n");	
	printf("  Name: %s\n", img_data->name);
        printf("  Type: %s\n", img_data->type);
        if (ft_strlen(img_data->comment) > 0)
                printf("  Comment:\n   %s", img_data->comment);
        printf("  Width: %d\n", img_data->width);
        printf("  Height: %d\n", img_data->height);
        printf("  Max-Value: %d\n", img_data->max_value);
	
        printf(BLUE "║" RESET "                                              " BLUE "║" RESET "\n");
        printf(BLUE "╚══════════════════════════════════════════════╝" RESET "\n");
        printf("\n");
}