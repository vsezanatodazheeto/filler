#include <stdio.h>
#include <stdlib.h>

typedef struct			s_f
{
	int					ally;
    struct s_f			*next;
    struct s_f			*prev;
}						t_f;

t_f		*new_t_f()
{
	t_f	*ptr;

	ptr = malloc(sizeof(t_f));
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);

}
void	add_struct(t_f *lst)
{
	t_f *ptr;

	ptr = new_t_f();
	lst->next = ptr;
	return ;
}

int			ft_strtospace(char *s, char ch)
{
	int		i;

	i = 0;
	while (s)
	{
		if (*s == ch)
			return (i + 1);
		i++;
		s++;
	}
	return (0);
}

int		main()
{
	char *line;

	line = "here we go";

	printf("%s\n", line + ft_strintch(line, ' '));
	// int i;
	// t_f *lst;
	// t_f *cur;

	// lst = new_t_f();
	// cur = lst;

	// add_struct(cur);
	// cur = cur->next;
	// add_struct(cur);
	// cur = cur->next;
	// add_struct(cur);
	// cur = cur->next;
	// add_struct(cur);
	// cur = cur->next;
	// while (lst->next)
	// {
	// 	lst = lst->next;
	// 	printf("kek\n");
	// }
	return (0);
}