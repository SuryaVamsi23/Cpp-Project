#include "AngleBar2.hpp"
#include "ComponentManager.hpp"
AngleBar2::AngleBar2(string s, int v) : Component(s)
{
    startTime = SDL_GetTicks();
    mouse = new Mouse;
    isClicked = false;
    count = 0;
    r = new SDL_Rect();
    r->x = 450;
    r->y = 390;
    r->w = 100;
    r->h = 75;
    AngleBarButton = new Button(r->x, r->y, r->h, r->w, "AngleBar.png");
    animate();
    velocity = v;
    bar_render_ticks = 0;
    surface = IMG_Load("AngleBar.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void AngleBar2::animate()
{
    rects[0].x = 28;
    rects[0].y = 2;
    rects[0].h = 18;
    rects[0].w = 162;

    rects[1].x = 28;
    rects[1].y = 23;
    rects[1].h = 18;
    rects[1].w = 162;

    rects[2].x = 28;
    rects[2].y = 44;
    rects[2].h = 18;
    rects[2].w = 162;

    rects[3].x = 28;
    rects[3].y = 65;
    rects[3].h = 18;
    rects[3].w = 162;

    rects[4].x = 28;
    rects[4].y = 85;
    rects[4].h = 18;
    rects[4].w = 162;

    rects[5].x = 28;
    rects[5].y = 107;
    rects[5].h = 18;
    rects[5].w = 162;

    rects[6].x = 28;
    rects[6].y = 128;
    rects[6].h = 18;
    rects[6].w = 162;

    rects[7].x = 28;
    rects[7].y = 150;
    rects[7].h = 18;
    rects[7].w = 162;

    rects[8].x = 28;
    rects[8].y = 170;
    rects[8].h = 18;
    rects[8].w = 162;

    rects[9].x = 28;
    rects[9].y = 191;
    rects[9].h = 18;
    rects[9].w = 162;
}

void AngleBar2::handleEvents()
{
    if (isActiveComponent)
    {
        if (AngleBarButton->isclicked(mouse))
        {
            isClicked = true;
            endTime = SDL_GetTicks();
        }
    }
}
void AngleBar2::update(vector<Component *> &Components, bool *isRunning)
{
    Uint32 CurrentTime = SDL_GetTicks();


    if (isClicked == true && isActiveComponent)
    {
        for (int i = 0; i < Components.size(); i++)
        {
            if (Components[i]->get_type() == "Abar")
                Components[i]->setInactive();

            if (Components[i]->get_type() == "sball")
                Components[i]->setInactive();

            if(Components[i]->get_type()=="dustbin")
                Components[i]->setInactive();
        }
        isClicked = false;
        count++;
        angle = 9 * count;
        Component *mb = new MovingPaperBall2("Mpaper", velocity, angle);
        Component *db = new Dustbin2("dustbin");
        mb->setActive();
        db->setActive();
        Components.push_back(mb);
        Components.push_back(db);
    }
}
bool AngleBar2::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        Uint32 currentTime = SDL_GetTicks();

        SDL_RenderCopy(renderer, texture,&rects[count], r);
        bar_render_ticks++;
        if(bar_render_ticks%4==0)
            count++;
        if(count == 10)
            count = 0;
    }
    return (true);
}