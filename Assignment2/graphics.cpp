//Alexander Young
//Assignment 2

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "logic.h"

void get_mouse_input(int x, int y, logic &gameLogic);
void draw_objects(int x, int y, int index1, int index2, logic &gameLogic);
void draw_grid();
void draw_status();
void draw_square(int x, int y);
void draw_circle(int x, int y);
void draw_rectangle(int x, int y);
void draw_oval(int x, int y);

int mx, my;

int main(void)
{
    logic gameLogic;
    bool done = false, flip = false;
    char shape = ' ';
    int count = 0;
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
    gameLogic.set_shape(0, 0, 'r');
    gameLogic.set_shape(1, 0, 's');
    gameLogic.set_shape(2, 0, 'c');
    gameLogic.set_shape(3, 0, 'o');
    gameLogic.set_shape(4, 0, 'r');
    gameLogic.set_shape(0, 1, 'r');
    gameLogic.set_shape(1, 1, 's');
    gameLogic.set_shape(2, 1, 'c');
    gameLogic.set_shape(3, 1, 'o');
    gameLogic.set_shape(4, 1, 'r');
    
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
                get_mouse_input(mx, my, gameLogic);
                al_draw_textf(font, al_map_rgb(0, 0, 0), mx, my, 0, "%i, %i", mx, my);
                count++;
                flip = false;
            }
        }
        if (count == 2) {
            al_flip_display();
            al_rest(3);
            al_clear_to_color(al_map_rgb(255, 255, 255));
            draw_grid();
            count = 0;
        }
        al_flip_display();
    }
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    al_destroy_font(font);
}

void get_mouse_input(int x, int y, logic &gameLogic) {
    if (x >= 0 && x < 99) {
        if (y >= 0 && y < 119) {
            draw_objects(50, 60, 0, 0, gameLogic);
        }
        else if (y >= 120 && y < 239) {
            draw_objects(50, 180, 1, 0, gameLogic);
        }
        else if (y >= 240 && y < 359) {
            draw_objects(50, 300, 2, 0, gameLogic);
        }
        else if (y >= 360 && y < 479) {
            draw_objects(50, 420, 3, 0, gameLogic);
        }
        else if (y >= 480 && y < 599) {
            draw_objects(50, 540, 4, 0, gameLogic);
        }
    }
    else if (x >= 100 && x < 199) {
        if (y >= 0 && y < 119) {
            draw_objects(150, 60, 0, 1, gameLogic);
        }
        else if (y >= 120 && y < 239) {
            draw_objects(150, 180, 1, 1, gameLogic);
        }
        else if (y >= 240 && y < 359) {
            draw_objects(150, 300, 2, 1, gameLogic);
        }
        else if (y >= 360 && y < 479) {
            draw_objects(150, 420, 3, 1, gameLogic);
        }
        else if (y >= 480 && y < 599) {
            draw_objects(150, 540, 4, 1, gameLogic);
        }
    }
    else if (x >= 200 && x < 299) {
        if (y >= 0 && y < 99) {
            draw_objects(250, 60, 0, 2, gameLogic);
        }
        else if (y >= 100 && y < 199) {
            draw_objects(250, 180, 1, 2, gameLogic);
        }
        else if (y >= 200 && y < 299) {
            draw_objects(250, 300, 2, 2, gameLogic);
        }
        else if (y >= 300 && y < 399) {
            draw_objects(250, 420, 3, 2, gameLogic);
        }
        else if (y >= 400 && y < 499) {
            draw_objects(250, 540, 4, 2, gameLogic);
        }
    }
    else if (x >= 300 && x < 399) {
        if (y >= 0 && y < 99) {
            draw_objects(350, 60, 0, 3, gameLogic);
        }
        else if (y >= 100 && y < 199) {
            draw_objects(350, 180, 1, 3, gameLogic);
        }
        else if (y >= 200 && y < 299) {
            draw_objects(350, 300, 2, 3, gameLogic);
        }
        else if (y >= 300 && y < 399) {
            draw_objects(350, 420, 3, 3, gameLogic);
        }
        else if (y >= 400 && y < 499) {
            draw_objects(350, 540, 4, 3, gameLogic);
        }
    }
    else if (x >= 400 && x < 499) {
        if (y >= 0 && y < 99) {
            draw_objects(450, 60, 0, 4, gameLogic);
        }
        else if (y >= 100 && y < 199) {
            draw_objects(450, 180, 1, 4, gameLogic);
        }
        else if (y >= 200 && y < 299) {
            draw_objects(450, 300, 2, 4, gameLogic);
        }
        else if (y >= 300 && y < 399) {
            draw_objects(450, 420, 3, 4, gameLogic);
        }
        else if (y >= 400 && y < 499) {
            draw_objects(450, 540, 4, 4, gameLogic);
        }
    }
}
void draw_objects(int x, int y, int index1, int index2, logic &gameLogic) {
    if (gameLogic.get_shape(index1, index2) == 'r') {
        draw_rectangle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 's') {
        draw_square(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'c') {
        draw_circle(x, y);
    }
    else if (gameLogic.get_shape(index1, index2) == 'o') {
        draw_oval(x, y);
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
}
void draw_status() {

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
    al_draw_filled_ellipse(x, y, 45, 20, al_map_rgb(255, 255, 0));
}
