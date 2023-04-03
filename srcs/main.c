
#include "../minishell.h"

int	main(int argc, char **argv/*, char **envp*/)
{
	if (argc == 1)
	{
		char	*rl;

		rl = "0";
		while (ft_strncmp(rl, "exit", ft_strlen(rl)) != 0)
		{
			rl = readline("minishell-1.0$ ");
			readline_to_tab(rl);
		}
		return (0);
	}
	perror(argv[1]);
	return (0);
}
