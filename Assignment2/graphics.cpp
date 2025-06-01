//Alexander Young
//Assignment 2

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "graphics.h"
#include "logic.h"

int mx, my;

int main(void)
{
    logic gameLogic;
    graphics graphic;
    bool done = false, flip = false;
    char shape;
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

    al_register_event_source(eventQueue, al_get_mouse_event_source());
    gameLogic.set_shape(0, 0, 'r');
    while (!done) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(eventQueue, &ev);
        al_clear_to_color(al_map_rgb(255, 255, 255));
        graphic.draw_grid();
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (ev.mouse.button & 1) {
                mx = ev.mouse.x;
                my = ev.mouse.y;
                flip = true;
            }
        }
        if (flip == true) {
            graphic.get_mouse_input(mx, my);
            graphic.draw_objects(mx, my, gameLogic);
        }
        al_flip_display();
    }
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    al_destroy_font(font);
}

void graphics::get_mouse_input(int x, int y) {
    if (x >= 0 && x < 99) {
        if (y >= 0 && y < 99) {
            x = 50;
            y = 50;
        }
        else if (y >= 100 && y < 199) {
            x = 50;
            y = 150;
        }
        else if (y >= 200 && y < 299) {
            x = 50;
            y = 250;
        }
        else if (y >= 300 && y < 399) {
            x = 50;
            y = 350;
        }
        else if (y >= 400 && y < 499) {
            x = 50;
            y = 450;
        }
    }
    else if (x >= 100 && x < 199) {
        if (y >= 0 && y < 99) {
            x = 150;
            y = 50;
        }
        else if (y >= 100 && y < 199) {
            x = 150;
            y = 150;
        }
        else if (y >= 200 && y < 299) {
            x = 150;
            y = 250;
        }
        else if (y >= 300 && y < 399) {
            x = 150;
            y = 350;
        }
        else if (y >= 400 && y < 499) {
            x = 150;
            y = 450;
        }
    }
    else if (x >= 200 && x < 299) {
        if (y >= 0 && y < 99) {
            x = 250;
            y = 50;
        }
        else if (y >= 100 && y < 199) {
            x = 250;
            y = 150;
        }
        else if (y >= 200 && y < 299) {
            x = 250;
            y = 250;
        }
        else if (y >= 300 && y < 399) {
            x = 250;
            y = 350;
        }
        else if (y >= 400 && y < 499) {
            x = 250;
            y = 450;
        }
    }
    else if (x >= 300 && x < 399) {
        if (y >= 0 && y < 99) {
            x = 350;
            y = 50;
        }
        else if (y >= 100 && y < 199) {
            x = 350;
            y = 150;
        }
        else if (y >= 200 && y < 299) {
            x = 350;
            y = 250;
        }
        else if (y >= 300 && y < 399) {
            x = 350;
            y = 350;
        }
        else if (y >= 400 && y < 499) {
            x = 350;
            y = 450;
        }
    }
    else if (x >= 400 && x < 499) {
        if (y >= 0 && y < 99) {
            x = 450;
            y = 50;
        }
        else if (y >= 100 && y < 199) {
            x = 450;
            y = 150;
        }
        else if (y >= 200 && y < 299) {
            x = 450;
            y = 250;
        }
        else if (y >= 300 && y < 399) {
            x = 450;
            y = 350;
        }
        else if (y >= 400 && y < 499) {
            x = 450;
            y = 450;
        }
    }
}
void graphics::draw_objects(int x, int y, logic &gameLogic) {
    char shape = gameLogic.get_shape(x, y);
    if (shape == 'r') {
        draw_rectangle(x, y);
    }
}
void graphics::draw_grid() {
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
void graphics::draw_status() {

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
