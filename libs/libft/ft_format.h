/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:50:43 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/03 14:08:58 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

/*
Things to add:
	- Other macros for weird ansi codes relating to the cursor in the terminal
	- Background color
	- Foreground color
	- etc.
*/

// Reset all settings:
# define ANSI_RESET	"\x1b[0m"
# ifndef RESET
#  define RESET ANSI_RESET
# endif

/* >> Colors << */
// Simple:
# define ANSI_COLOR_BLACK	"\x1b[30m"
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_WHITE	"\x1b[37m"
# define ANSI_COLOR_RESET	"\x1b[39m"

// Bright:
# define ANSI_COLOR_BRIGHT_BLACK	"\x1b[90m"
# define ANSI_COLOR_BRIGHT_RED		"\x1b[91m"
# define ANSI_COLOR_BRIGHT_GREEN	"\x1b[92m"
# define ANSI_COLOR_BRIGHT_YELLOW	"\x1b[93m"
# define ANSI_COLOR_BRIGHT_BLUE		"\x1b[94m"
# define ANSI_COLOR_BRIGHT_MAGENTA	"\x1b[95m"
# define ANSI_COLOR_BRIGHT_CYAN		"\x1b[96m"
# define ANSI_COLOR_BRIGHT_WHITE	"\x1b[97m"

//// Color aliases:
# define F_BLACK	ANSI_COLOR_BLACK
# define F_RED		ANSI_COLOR_RED
# define F_GREEN	ANSI_COLOR_GREEN
# define F_YELLOW	ANSI_COLOR_YELLOW
# define F_BLUE		ANSI_COLOR_BLUE
# define F_MAGENTA	ANSI_COLOR_MAGENTA
# define F_CYAN		ANSI_COLOR_CYAN
# define F_WHITE	ANSI_COLOR_WHITE
# define F_BBLACK	ANSI_COLOR_BRIGHT_BLACK
# define F_BRED		ANSI_COLOR_BRIGHT_RED
# define F_BGREEN	ANSI_COLOR_BRIGHT_GREEN
# define F_BYELLOW	ANSI_COLOR_BRIGHT_YELLOW
# define F_BBLUE	ANSI_COLOR_BRIGHT_BLUE
# define F_BMAGENTA	ANSI_COLOR_BRIGHT_MAGENTA
# define F_BCYAN	ANSI_COLOR_BRIGHT_CYAN
# define F_BWHITE	ANSI_COLOR_BRIGHT_WHITE

/* >> Graphic modes << */

// Set:
# define ANSI_SET_BOLD				"\x1b[1m"
# define ANSI_SET_DIM				"\x1b[2m"
# define ANSI_SET_ITALIC			"\x1b[3m"
# define ANSI_SET_UNDERLINE			"\x1b[4m"
# define ANSI_SET_BLINKING			"\x1b[5m"
# define ANSI_SET_INVERSE			"\x1b[7m"
# define ANSI_SET_HIDDEN			"\x1b[8m"
# define ANSI_SET_STRIKETHROUGH		"\x1b[9m"

// Reset:
# define ANSI_RESET_BOLD			"\x1b[22m"
# define ANSI_RESET_DIM				"\x1b[22m"
# define ANSI_RESET_ITALIC			"\x1b[23m"
# define ANSI_RESET_UNDERLINE		"\x1b[24m"
# define ANSI_RESET_BLINKING		"\x1b[25m"
# define ANSI_RESET_INVERSE			"\x1b[27m"
# define ANSI_RESET_HIDDEN			"\x1b[28m"
# define ANSI_RESET_STRIKETHROUGH	"\x1b[29m"

//// Mode aliases:
# define F_BOLD				ANSI_SET_BOLD
# define F_DIM				ANSI_SET_DIM
# define F_ITALIC			ANSI_SET_ITALIC
# define F_UNDERLINE		ANSI_SET_UNDERLINE
# define F_BLINKING			ANSI_SET_BLINKING
# define F_INVERSE			ANSI_SET_INVERSE
# define F_HIDDEN			ANSI_SET_HIDDEN
# define F_STRIKETHROUGH	ANSI_SET_STRIKETHROUGH

# define F_RBOLD			ANSI_RESET_BOLD
# define F_RDIM				ANSI_RESET_DIM
# define F_RITALIC			ANSI_RESET_ITALIC
# define F_RUNDERLINE		ANSI_RESET_UNDERLINE
# define F_RBLINKING		ANSI_RESET_BLINKING
# define F_RINVERSE			ANSI_RESET_INVERSE
# define F_RHIDDEN			ANSI_RESET_HIDDEN
# define F_RSTRIKETHROUGH	ANSI_RESET_STRIKETHROUGH

# ifndef BOLD
#  define BOLD F_BOLD
# endif
# ifndef DIM
#  define DIM F_DIM
# endif
# ifndef ITALIC
#  define ITALIC F_ITALIC
# endif
# ifndef UNDERLINE
#  define UNDERLINE F_UNDERLINE
# endif
# ifndef BLINKING
#  define BLINKING F_BLINKING
# endif
# ifndef HIDDEN
#  define HIDDEN F_HIDDEN
# endif
# ifndef STRIKETHROUGH
#  define STRIKETHROUGH F_STRIKETHROUGH
# endif

# ifndef RBOLD
#  define RBOLD F_RBOLD
# endif
# ifndef RDIM
#  define RDIM F_RDIM
# endif
# ifndef RITALIC
#  define RITALIC F_RITALIC
# endif
# ifndef RUNDERLINE
#  define RUNDERLINE F_RUNDERLINE
# endif
# ifndef RBLINKING
#  define RBLINKING F_RBLINKING
# endif
# ifndef RHIDDEN
#  define RHIDDEN F_RHIDDEN
# endif
# ifndef RSTRIKETHROUGH
#  define RSTRIKETHROUGH F_RSTRIKETHROUGH
# endif

#endif // FT_FORMAT_H
