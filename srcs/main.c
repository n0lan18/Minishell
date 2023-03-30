
#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		char	*rl;

		rl = readline("minishell-1.0$ ");
		while (rl != NULL)
		{
			rl = readline("minishell-1.0$ ");
			if (ft_strncmp(rl, "exit", ft_strlen(rl)) == 0)
				break ;
		}
	}
	perror(argv[1]);
	return (0);
}
