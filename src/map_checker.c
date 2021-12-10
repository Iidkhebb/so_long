#include "so_long.h"
int ft_char_line_count(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
    {
        i++;
    }
    return(i); 
}
void ft_check_horz_wall(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        if (line[i] != '1')
        {
            ft_putstr("Error while checking the wall\n");
            ft_putstr("Your map has to be surrounded from the top by Wall => 1\n");
            exit(0);
        }
        i++;
    }
}

void ft_check_sides(char *line)
{
    int i;

    i = 0;
    if (line[0] != '1' || line[ft_strlen2(line) - 2] != '1')
    {
        ft_putstr("Error while checking the side walls\n");
        ft_putstr("Your map has to be started & ended from the sides by a Wall => 1\n");
        exit(0);
    }
}

void ft_check_map_shap(char *line)
{
    static int line_len;

    if (!line_len)
    {
        line_len = ft_char_line_count(line);
    }
    else
    {
        if (line_len != ft_char_line_count(line))
        {
            ft_putstr("Error\n");
            ft_putstr("The shap of the map has to be valid\n");
            exit(0);
        }
    }
}

void ft_check_elements(char *line)
{
    int i;

    i = 0;
    if (!e.player)
        e.player = 0;
    if (!e.collectibles)
        e.collectibles = 0;
    if (!e.exits)
        e.exits = 0;
    if (line[0] == '\0' && (e.player == 0 || e.collectibles == 0 || e.exits == 0 || e.player >= 2))
    {
        ft_putstr("Error\n");
        if (e.player == 0 || e.player >= 2)
            ft_putstr("You must have one player to start the game.\n");
        if(e.collectibles == 0)
            ft_putstr("You must have at least one collectibles to start the game.\n");
        if(e.exits == 0)
            ft_putstr("You must have at least one exit to start the game.\n");
        exit(0);    
    }
    while (line[i] != '\0')
    {
        if (line[i] == 'E')
            e.exits += 1;
        if(line[i] == 'C')
            e.collectibles += 1;
        if(line[i] == 'P')
            e.player += 1;
        i++;
    }
}