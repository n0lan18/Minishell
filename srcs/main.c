
#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		char	*rl;
        char    **tab;
        t_param inc;

        inc.i = 0;
        inc.j = 0;
        inc.deb = 0;
		rl = "0";
		while (ft_strncmp(rl, "exit", ft_strlen(rl)) != 0)
        {
            inc.i = 0;
            inc.j = 0;
            inc.deb = 0;
			rl = readline("minishell-1.0$ ");
            tab = readline_to_tab(rl);
            tab = check_if_dollar(tab, envp, inc);
            while (tab[inc.i])
                printf("%s\n", tab[inc.i++]);
            free_double_tab(tab);
        }
		return (0);
	}
	perror(argv[1]);
	return (0);
}
