#include <curses.h>

int main() {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);


    box(stdscr, 0, 0);

    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(1, 2, "LIBRARY SYSTEM - TUI DEMO");
    attroff(COLOR_PAIR(1) | A_BOLD);

    mvhline(2, 1, ACS_HLINE, COLS-2);

    attron(COLOR_PAIR(2));
    mvprintw(4, 2, "[K001] A Gyűrűk Ura - Tolkien (elérhető)");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(5, 2, "[K002] Harry Potter - Rowling (kölcsönözve)");
    attroff(COLOR_PAIR(3));

    mvprintw(LINES - 2, 2, "Nyomj meg egy billentyűt a kilépéshez...");

    refresh();
    getch();

    endwin();
    return 0;
}
