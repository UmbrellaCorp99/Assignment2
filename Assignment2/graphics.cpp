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

int main(void)
{
    logic gameLogic;
    graphics graphic;
    bool done = false;
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
    al_init_primitives_addon();
    while (!done) {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        graphic.draw_grid();
        al_flip_display();
    }
    al_destroy_display(display);
}

void graphics::get_mouse_input() {

}
void graphics::draw_objects() {
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
