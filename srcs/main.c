
#include "../minishell.h"

int	main(int argc, char **argv/*, char **envp*/)
{
	if (argc == 1)
	{
		char	*rl;
		t_list	*liste;

		liste = NULL;
		rl = "0";
		while (ft_strncmp(rl, "exit", ft_strlen(rl)) != 0)
        {
			liste = NULL;
			rl = readline("minishell-1.0$ ");
			liste = split_new_format(rl, liste);
			while (liste)
			{
				printf("LISTE %s\n", liste->str);
				liste = liste->next;
			}
        }
		return (0);
	}
	perror(argv[1]);
	return (0);
}
