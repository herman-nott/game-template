#include "./uielement.h"

UIELEMENT create_element(int pos_x, int pos_y, SDL_Texture* image)
{
    UIELEMENT u;

    u.posX = pos_x;
    u.posY = pos_y;
    u.image = image;
    return u;
}

void draw_element(SDL_Renderer* renderer, UIELEMENT *u, int imageW, int imageH)
{
    SDL_Rect srcRect, dstRect;
    SDL_QueryTexture(u->image, NULL, NULL, &imageW, &imageH);
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = imageW;
    srcRect.h = dstRect.h = imageH;
    dstRect.x = u->posX;
    dstRect.y = u->posY;
    SDL_RenderCopy(renderer, u->image, &srcRect, &dstRect);
}