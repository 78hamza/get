# include "get_next_line.h"

char    *update_pocket(char *pocket)
{
    int i;
    int j;
    char    *updated_pocket;

    i = 0;
    while (pocket[i] && pocket[i] != '\n')
        i++;
    if (pocket[i] == '\0')
    {
        free(pocket);
        return (NULL);
    }
    updated_pocket = malloc(ft_strlen(pocket) - i + 1);
    if (!updated_pocket)
        return (NULL);
    i++;
    j = 0;
    while (pocket[i])
        updated_pocket[j++] = pocket[i++];
    updated_pocket[j] = '\0';
    free(pocket);
    return (updated_pocket);
}

char    *extract_pocket(char *pocket)
{
    int i;
    char    *extracted_pocket;

    i = 0;
    if (!pocket || pocket[i] == '\0')
        return (NULL);
    while (pocket[i] && pocket[i] != '\n')
        i++;
    extracted_pocket = malloc(i + 2);
    if (!extracted_pocket)
        return (NULL);
    i = 0;
    while (pocket[i] && pocket[i] != '\n')
    {
        extracted_pocket[i] = pocket[i];
        i++;
    }
    if (pocket[i] == '\n')
    {
        extracted_pocket[i] = pocket[i];
        i++;
    }
    extracted_pocket[i] = '\0';
    return (extracted_pocket);
}

char    *read_and_join(int fd, char *pocket)
{
    char    *buffer;
	char	*tmp;
    ssize_t bytes;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(pocket, '\n') && bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(buffer);
            free(pocket);
            return (NULL);
        }
        buffer[bytes] = '\0';
		tmp = ft_strjoin(pocket, buffer);
        free(pocket);
		pocket = tmp;
    }
    free(buffer);
    return (pocket);
}

char    *get_next_line(int fd)
{
    static char *pocket;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    pocket = read_and_join(fd, pocket);
    if (!pocket)
        return (NULL);
    line = extract_pocket(pocket);
    if (!line)
    {
        free(pocket);
        pocket = NULL;
        return (NULL);
    }
    pocket = update_pocket(pocket);
    return (line);
}