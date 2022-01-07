#include "AngleBar.hpp"
#include "ComponentManager.hpp"
AngleBar::AngleBar(string s, int v) : Component(s)
{
    startTime = SDL_GetTicks();
    mouse = new Mouse;
    isClicked = false;
    r = new SDL_Rect();
    r->x = 400;
    r->y = 390;
    r->w = 150;
    r->h = 75;
    AngleBarButton = new Button(r->x, r->y, r->h, r->w, "AngleBar.png");
    animateAngleBar();
    count = 0;
    velocity = v;
    angle_max = 90;
    bar_render_ticks = 0;
    surface = IMG_Load("AngleBar.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void AngleBar::animateAngleBar()
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

void AngleBar::handleEvents()
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
void AngleBar::update(vector<Component *> &Components, bool *isRunning)
{
    Uint32 CurrentTime = SDL_GetTicks();
    if (isClicked == true)
    {
        for (int i = 0; i < Components.size(); i++)
        {
            if (Components[i]->get_type() == "Angle bar")
                Components[i]->setInactive();

            if (Components[i]->get_type() == "Stationary paper")
                Components[i]->setInactive();

            if (Components[i]->get_type() == "Dust bin")
                Components[i]->setInactive();
        }
        isClicked = false;
        count++;
        angle = angle_max*count/10;
        Component *mb = new MovingPaperBall("Moving paper", velocity, angle);
        mb->setActive();
        Component *db = new Dustbin("dustbin");
        db->setActive();
        Components.push_back(mb);
        Components.push_back(db);
    }
}
bool AngleBar::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        Uint32 currentTime = SDL_GetTicks();
        SDL_RenderCopy(renderer, texture, &rects[count], r);
        bar_render_ticks++;
         if (bar_render_ticks % 9 == 1)
            count++;
        if (count == 10)
            count = 0;
    }
    return (true);
}