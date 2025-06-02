//Alexander Young
//Assignment 2

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "logic.h"
#include <time.h>

void get_mouse_input(int x, int y, int &index1, int &index2);
void draw_objects(int index1, int index2, logic &gameLogic);
void draw_grid();
void draw_status();
void draw_square(int x, int y);
void draw_circle(int x, int y);
void draw_rectangle(int x, int y);
void draw_oval(int x, int y);
void draw_triangle(int x, int y);
void draw_arc(int x, int y);
void draw_green_square(int x, int y);
void draw_red_circle(int x, int y);
void draw_orange_rectangle(int x, int y);
void draw_purple_oval(int x, int y);
void draw_yellow_triangle(int x, int y);
void draw_blue_arc(int x, int y);
void draw_X(int index1, int index2);

int mx, my;

int main(void)
{
    logic gameLogic;
    bool done = false, flip = false;
    char shape = ' ';
    int count = 0;
    int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
    int points = 0;
    srand(time(0));

    ALLEGRO_DISPLAY *display = NULL;
    if (!al_init()) {
        al_show_native_message_box(NULL, "Error", "Allegro failed to initialize", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    int width = 800, height = 600;
    display = al_create_display(width, height);
    if (display == NULL) {
        al_show_native_message_box(NULL, "Error", "Failed to create display", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    ALLEGRO_EVENT_QUEUE* eventQueue = NULL;

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* font = al_load_font("Movistar Text Regular.ttf", 24, 0);
   
    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_clear_to_color(al_map_rgb(255, 255, 255));
    

    if (!al_install_mouse()) {
        al_show_native_message_box(display, "Error", "Failed to initialize mouse", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    gameLogic.setup();
    al_register_event_source(eventQueue, al_get_mouse_event_source());

    draw_grid();
    al_flip_display();
    while (!done) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(eventQueue, &ev);
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        draw_grid();
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (ev.mouse.button & 1) {
                mx = ev.mouse.x;
                my = ev.mouse.y;
                flip = true;
            }
        }
        if (flip) {
            if (mx >= 0 and mx <= 600) {
                if (count == 0) {
                    get_mouse_input(mx, my, index1, index2);
                    if (index1 == 4 && index2 == 4) {
                        gameLogic.reset_clear();
                        count = 0;
                        points = 0;
                        al_clear_to_color(al_map_rgb(255, 255, 255));
                        draw_grid();
                        al_flip_display();
                    }
                    else {
                        draw_objects(index1, index2, gameLogic);
                        al_flip_display();
                        count++;
                        flip = false;
                    }
                }
                else if (count == 1) {
                    get_mouse_input(mx, my, index3, index4);
                    if (index3 == 4 && index4 == 4) {
                        gameLogic.reset_clear();
                        count = 0;
                        points = 0;
                        al_clear_to_color(al_map_rgb(255, 255, 255));
                        draw_grid();
                        al_flip_display();
                    }
                    else {
                        draw_objects(index3, index4, gameLogic);
                        al_flip_display();
                        count++;
                        flip = false;
                    }
                }
            }
        }
        if (count == 2) {
            if (gameLogic.compare(index1, index2, index3, index4)) {
                gameLogic.correctGuess(index1, index2);
                gameLogic.correctGuess(index3, index4);
                points++;
                count = 0;
                al_rest(2);
                al_clear_to_color(al_map_rgb(255, 255, 255));
                draw_grid();
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++)
                        if (gameLogic.get_shape(i, j) == 'X') {
                            draw_objects(i, j, gameLogic);
                        }
                }
                al_flip_display();
            }
            else {
                count = 0;
                al_rest(2);
                al_clear_to_color(al_map_rgb(255, 255, 255));
                draw_grid();
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++)
                        if (gameLogic.get_shape(i, j) == 'X') {
                            draw_objects(i, j, gameLogic);
                        }
                }
                al_flip_display();
            }
        }
    }
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    al_destroy_font(font);
}
void get_mouse_input(int x, int y, int &index1, int &index2) {
    if (x >= 0 && x < 99) {
        if (y >= 0 && y < 119) {
            index1 = 0;
            index2 = 0;
        }
        else if (y >= 120 && y < 239) {
            index1 = 1;
            index2 = 0;
        }
        else if (y >= 240 && y < 359) {
            index1 = 2;
            index2 = 0;
        }
        else if (y >= 360 && y < 479) {
            index1 = 3;
            index2 = 0;
        }
        else if (y >= 480 && y < 599) {
            index1 = 4;
            index2 = 0;
        }
    }
    else if (x >= 100 && x < 199) {
        if (y >= 0 && y < 119) {
            index1 = 0;
            index2 = 1;
        }
        else if (y >= 120 && y < 239) {
            index1 = 1;
            index2 = 1;
        }
        else if (y >= 240 && y < 359) {
            index1 = 2;
            index2 = 1;
        }
        else if (y >= 360 && y < 479) {
            index1 = 3;
            index2 = 1;
        }
        else if (y >= 480 && y < 599) {
            index1 = 4;
            index2 = 1;
        }
    }
    else if (x >= 200 && x < 299) {
        if (y >= 0 && y < 119) {
            index1 = 0;
            index2 = 2;
        }
        else if (y >= 100 && y < 239) {
            index1 = 1;
            index2 = 2;
        }
        else if (y >= 200 && y < 359) {
            index1 = 2;
            index2 = 2;
        }
        else if (y >= 300 && y < 479) {
            index1 = 3;
            index2 = 2;
        }
        else if (y >= 400 && y < 599) {
            index1 = 4;
            index2 = 2;
        }
    }
    else if (x >= 300 && x < 399) {
        if (y >= 0 && y < 119) {
            index1 = 0;
            index2 = 3;
        }
        else if (y >= 100 && y < 239) {
            index1 = 1;
            index2 = 3;
        }
        else if (y >= 200 && y < 359) {
            index1 = 2;
            index2 = 3;
        }
        else if (y >= 300 && y < 479) {
            index1 = 3;
            index2 = 3;
        }
        else if (y >= 400 && y < 599) {
            index1 = 4;
            index2 = 3;
        }
    }
    else if (x >= 400 && x < 499) {
        if (y >= 0 && y < 119) {
            index1 = 0;
            index2 = 4;
        }
        else if (y >= 100 && y < 239) {
            index1 = 1;
            index2 = 4;
        }
        else if (y >= 200 && y < 359) {
            index1 = 2;
            index2 = 4;
        }
        else if (y >= 300 && y < 479) {
            index1 = 3;
            index2 = 4;
        }
        else if (y >= 400 && y < 599) {
            index1 = 4;
            index2 = 4;
        }
    }
}
void draw_objects(int index1, int index2, logic &gameLogic) {
    int x = 0;
    int y = 0;
    if (index1 == 0) {
        y = 60;
    }
    else if (index1 == 1) {
        y = 180;
    }
    else if (index1 == 2) {
        y = 300;
    }
    else if (index1 == 3) {
        y = 420;
    }
    else if (index1 == 4) {
        y = 540;
    }
    if (index2 == 0) {
        x = 50;
    }
    else if (index2 == 1) {
        x = 150;
    }
    else if (index2 == 2) {
        x = 250;
    }
    else if (index2 == 3) {
        x = 350;
    }
    else if (index2 == 4) {
        x = 450;
    }
    if (gameLogic.get_shape(index1, index2) == 'a') {
        draw_rectangle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'b') {
        draw_square(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'c') {
        draw_circle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'd') {
        draw_oval(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'e') {
        draw_triangle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'f') {
        draw_arc(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'g') {
        draw_green_square(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'h') {
        draw_red_circle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'i') {
        draw_orange_rectangle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'j') {
        draw_purple_oval(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'k') {
        draw_yellow_triangle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'l') {
        draw_blue_arc(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'X') {
        draw_X(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'z') {
    }
}
void draw_grid() {
    al_draw_line(100, 0, 100, 600, al_map_rgb(0, 0, 0), 1);
    al_draw_line(200, 0, 200, 600, al_map_rgb(0, 0, 0), 1);
    al_draw_line(300, 0, 300, 600, al_map_rgb(0, 0, 0), 1);
    al_draw_line(400, 0, 400, 600, al_map_rgb(0, 0, 0), 1);
    al_draw_line(500, 0, 500, 600, al_map_rgb(0, 0, 0), 1);
 
    al_draw_line(0, 120, 500, 120, al_map_rgb(0, 0, 0), 1);
    al_draw_line(0, 240, 500, 240, al_map_rgb(0, 0, 0), 1);
    al_draw_line(0, 360, 500, 360, al_map_rgb(0, 0, 0), 1);
    al_draw_line(0, 480, 500, 480, al_map_rgb(0, 0, 0), 1);

    draw_status();
}
void draw_status() {
    int x = 450, y = 580;
    al_draw_filled_rectangle(x - 50, y - 100, x + 49, y + 60, al_map_rgb(0, 255, 0));
}
void draw_square(int x, int y) {
    al_draw_rectangle(x - 45, y - 45, x + 45, y + 45, al_map_rgb(255, 0, 0), 3);
}
void draw_circle(int x, int y) {
    al_draw_circle(x, y, 45, al_map_rgb(0, 255, 0), 3);
}
void draw_rectangle(int x, int y) {
    al_draw_rectangle(x - 45, y - 20, x + 45, y + 20, al_map_rgb(0, 0, 255), 3);
}
void draw_oval(int x, int y) {
    al_draw_ellipse(x, y, 45, 20, al_map_rgb(255, 255, 0), 3);
}
void draw_X(int x, int y) {
    al_draw_line(x - 50, y - 60, x + 50, y + 60, al_map_rgb(122, 0, 0), 3);
    al_draw_line(x + 50, y - 60, x - 50, y + 60, al_map_rgb(122, 0, 0), 3);
}
void draw_triangle(int x, int y) {
    al_draw_triangle(x - 45, y + 45, x + 45, y + 45, x, y - 45, al_map_rgb(255,0,255), 3);
}
void draw_arc(int x, int y) {
    al_draw_arc(x, y, 45, 90, 180, al_map_rgb(255, 165, 0), 3);
}
void draw_green_square(int x, int y) {
    al_draw_rectangle(x - 45, y - 45, x + 45, y + 45, al_map_rgb(0, 255, 0), 3);
}
void draw_red_circle(int x, int y) {
    al_draw_circle(x, y, 45, al_map_rgb(255, 0, 0), 3);
}
void draw_orange_rectangle(int x, int y) {
    al_draw_rectangle(x - 45, y - 20, x + 45, y + 20, al_map_rgb(255, 165, 0), 3);
}
void draw_purple_oval(int x, int y) {
    al_draw_ellipse(x, y, 45, 20, al_map_rgb(255, 0, 255), 3);
}
void draw_yellow_triangle(int x, int y) {
    al_draw_triangle(x - 45, y + 45, x + 45, y + 45, x, y - 45, al_map_rgb(255, 255, 0), 3);
}
void draw_blue_arc(int x, int y) {
    al_draw_arc(x, y, 45, 90, 180, al_map_rgb(0, 0, 255), 3);
}