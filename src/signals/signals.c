#include "signals.h"

void signal_handler(int sig)
{
	printf("\n");
	termios_handler();
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void termios_handler()
{
	struct termios old_termios, new_termios;

	tcgetattr(STDIN_FILENO, &old_termios);
	new_termios = old_termios;
	new_termios.c_lflag &= ~ISIG;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

// void handler_quit(int sig)
// {
// 	printf("Exit");
// 	exit(0);
// }
