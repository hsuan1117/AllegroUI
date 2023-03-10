#ifndef SELECTOR_H
#define SELECTOR_H

#include "utility.h"
#include "shared.h"
#include "game.h"
#include "TextButton.h"

typedef struct Selector {
    RecArea body, btn_body[2];
    bool hovered[2];
    char **items;
    int item_num;
    int now_selected;
    ALLEGRO_COLOR color;
    ALLEGRO_COLOR hovered_color;
    ALLEGRO_FONT *font;
    int rounded;
    int thickness;

    func_ptr_register event_register;
} Selector;

Selector selector_create(float x, float y, float w, float h, char **items, int item_num, int default_selection, ALLEGRO_COLOR color);
void drawSelector(Selector *selector);
void checkSelectorHovered(Selector *selector, int mouse_x, int mouse_y);
void selectorOnMouseDown(Selector *selector);

static void event_register(Selector *selector, ALLEGRO_EVENT event);
#endif
