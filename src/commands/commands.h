#ifndef COMMANDS_H
# define COMMANDS_H

# include "../src.h"

int		commands(t_shell *shell);
void	change_shlvl(t_shell *shell);
int     loop(t_shell *shell, int i, int j);

#endif
