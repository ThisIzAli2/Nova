/**
 * @author Ali Mirmohammad
 * @file video.h
 ** This file is part of Novanix.

**Novanix is free software: you can redistribute it and/or modify
**it under the terms of the GNU Affero General Public License as published by
**the Free Software Foundation, either version 3 of the License, or
**(at your option) any later version.

**Novanix is distributed in the hope that it will be useful,
**but WITHOUT ANY WARRANTY; without even the implied warranty of
**MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
**GNU Affero General Public License for more details.

**You should have received a copy of the GNU Affero General Public License
**along with Novanix. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _HEISEN_VIDEO_H
#define _HEISEN_VIDEO

#define _SCR_W 80
#define _SCR_H 25

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define GREY 7
#define DARK_GREY 8
#define BRIGHT_BLUE 9
#define BRIGHT_GREEN 10
#define BRIGHT_CYAN 11
#define BRIGHT_RED 12
#define BRIGHT_MAGENTA 13
#define YELLOW 14
#define WHITE 15


#define OK_POS 70

void _kntos(char*, unsigned int, int);
void _kputc(char);
void _kcolor(char);
void _kputs(char *);
void _kbackspace();
void _kesetcursor(unsigned int, unsigned int);
void _kgoto(int, int);
void _ksetcursauto();
void _kshiftAll();
void _ktab();
void _kclear();
void _knewline();
void _kminline();
void _kprintOK();
int _kgetline();
int _kgetcolumn();
void _krotate_buffer();
void _kscrollup();
void _kscrolldown();
void _kntohex (char *, unsigned int);
void _knntos(char *, int, int );
// unsigned short shell_mess_col, shell_mess_line;

#endif // 