
#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		char	*rl;
		t_list *liste;

		rl = "0";
		while (ft_strncmp(rl, "exit", ft_strlen(rl)) != 0)
        {
			liste = NULL;
			rl = readline("minishell-1.0$ ");
            liste = readline_to_tab(rl, liste);
			while (liste)
		 	{
				printf("l %s\n", liste->str);
				liste = liste->next;
		 	}
			liste = check_if_dollar(liste, envp);
			free_liste(liste);
        }
		return (0);
	}
	perror(argv[1]);
	return (0);
}
