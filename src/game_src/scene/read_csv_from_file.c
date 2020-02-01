/*
** EPITECH PROJECT, 2020
** ggj_2020
** File description:
** read_csv_from_file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **stock_line_in_array(char **last_stock, char *line, int line_size)
{
    char **new;
    int line_nb = 0;
    int j = 0;

    for (; last_stock != NULL && last_stock[line_nb] != NULL; line_nb++);
    new = malloc(sizeof(char *) * (line_nb + 2));
    for (int i = 0; last_stock != NULL && last_stock[i] != NULL; i++)
        new[i] = last_stock[i];
    free(last_stock);
    new[line_nb] = malloc(sizeof(char) * line_size + 2);
    for (; line[j] != '\0' && line[j] != '\n'; j++)
        new[line_nb][j] = line[j];
    new[line_nb][j] = '\0';
    new[line_nb + 1] = NULL;
    return (new);
}

char **read_from_stream(FILE *stream)
{
    char *buffer = NULL;
    char **map = NULL;
    size_t size = 0;
    int line = 0;

    while ((size = getline(&buffer, &size, stream)) != -1) {
        map = stock_line_in_array(map, buffer, size);
        free(buffer);
        buffer = NULL;
        line++;
    }
    free(buffer);
    return (map);
}

char **read_file(char *path)
{
    char *buffer = NULL;
    char **map = NULL;
    FILE *stream;
    int lines = 0;

    stream = fopen(path, "r");
    if (stream == NULL) {
        dprintf(2, "File couldn't be opened\n");
        return (NULL);
    }
    map = read_from_stream(stream);
    fclose(stream);
    return (map);
}

static char *remove_spaces_from_str(char *str)
{
    char *new = malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    int j = 0;

    for (; str[i]; i++) {
        if (str[i] != ' ') {
            new[j] = str[i];
            j++;
        }
    }
    new[j] = '\0';
    free(str);
    return (new);
}

int **read_csv_from_file(char *filepath)
{
    char **content = read_file(filepath);
    int **csv = 0;
    int x = 0;
    int i = 0;

    if (content == NULL)
        return (NULL);
    for (x = 0; content[x] != NULL; x++)
        content[x] = remove_spaces_from_str(content[x]);
    csv = malloc(sizeof(int *) * (x + 1));
    for (int y = 0; content[y]; y++) {
        for (int z = 0, x = 1; content[y][z]; z++)
            x += (content[y][z] == ',') ? 1 : 0;
        csv[y] = malloc(sizeof(int) * (x + 1));
    }
    for (; content[i]; i++) {
        x = 0;
        for (int j = 0; content[i][j]; j++, x++) {
            csv[i][x] = atoi(content[i] + j);
            for (; content[i][j] != ',' && content[i][j + 1] && content[i][j] != '\n'; j++);
        }
        csv[i][x] = -1;
    }
    csv[i] = malloc(sizeof(int) * 1);
    csv[i][0] = -2;
    for (int i = 0; content[i]; i++)
        free(content[i]);
    free(content);
    return (csv);
}