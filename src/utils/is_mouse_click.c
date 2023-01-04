/*
** EPITECH PROJECT, 2022
** is_mouse_over.c
** File description:
** desc
*/

#include <poke_window.h>

bool sprite_is_mouse_click(sprite_s *sprite_datas, sfEvent *event_datas)
{
    sfFloatRect sprite_bounds;
    sfVector2f pos;
    sfVector2f origin;
    sfVector2f scale;
    if (event_datas->type != sfEvtMouseButtonPressed
        && event_datas->type != sfEvtMouseButtonReleased)
        return false;
    pos = sfSprite_getPosition(sprite_datas->sf_sprite);
    sprite_bounds = sfSprite_getGlobalBounds(sprite_datas->sf_sprite);
    origin = sfSprite_getOrigin(sprite_datas->sf_sprite);
    scale = sfSprite_getScale(sprite_datas->sf_sprite);
    if (pos.x - (origin.x * scale.x) > (float)event_datas->mouseButton.x
        || (pos.x + (sprite_bounds.width - (origin.x * scale.x)))
           < (float)event_datas->mouseButton.x)
        return false;
    if (pos.y - (origin.y * scale.y) > (float)event_datas->mouseButton.y
        || (pos.y + (sprite_bounds.height - (origin.y * scale.y)))
           < (float)event_datas->mouseButton.y)
        return false;
    return true;
}
