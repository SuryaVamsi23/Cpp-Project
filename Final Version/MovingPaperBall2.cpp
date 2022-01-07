#include "MovingPaperBall2.hpp"
#include "PowerBar.hpp"
#include "ComponentManager.hpp"
MovingPaperBall2::MovingPaperBall2(string s, int v, int a) : Component(s)
{
    r = new SDL_Rect();
    r->x = 0;
    r->y = 370;
    r->w = 50;
    r->h = 50;
    startTime = SDL_GetTicks();
    velocity = v;
    //velocity = 14 * 6;
    angle = a;
    //angle = 9 * 7;
    win = false;
    entryflag = false;

    surface = IMG_Load("paper.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void MovingPaperBall2::handleEvents()
{
}

void MovingPaperBall2::update(vector<Component *> &Components, bool *isRunning)
{
    if(win == true)
    {
        *isRunning = false;
        return ;
    }
    Uint32 currentTime = SDL_GetTicks();
    Uint32 timeElapsed = currentTime - startTime;
    isActiveComponent = true;
    float in_radian = angle * 3.14159 / 180;
    double time_of_flight = (2 * velocity * sin(in_radian) / 10);
    double count = timeElapsed/100.0;

    r->x = velocity * cos(in_radian) * count;
    r->y = 370 - ((velocity * sin(in_radian) * count) - (5 * count) * (count));

    if(r->x > 400 && r->x < 550 && r->y >= 250 && r->y <= 265)
    {
        entryflag = true;
    }

    if(r->y>=365)
        r->y = 370;

}
bool MovingPaperBall2::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        if (r->x > 800 || r->y < 0 || r->y > 370)
        {
            int i;
            for (i = 0; i < Components.size(); i++)
            {
                Components[i]->setInactive();
            }
            Component *g = new Game_Background("Game Background");
            Component *d = new Dustbin("Dust bin");
            Component *p = new StationaryPaperBall("Stationary paper");
            Component *pbe = new PowerBar("Power bar");
            Component *e = new ExitButton("Exit button");
            g->setActive();
            d->setActive();
            p->setActive();
            pbe->setActive();
            e->setActive();
            Components.push_back(g);
            Components.push_back(d);
            Components.push_back(p);
            Components.push_back(pbe);
            Components.push_back(e);
            return (false);
        }
        if (r->x != 0 && (r->x < 400 || r->x>550) && r->y == 370)
        {
            SDL_RenderCopy(renderer, texture, NULL, r);
            int i;
            for (i = 0; i < Components.size(); i++)
            {
                Components[i]->setInactive();
            }
            Component *g = new Game_Background("Game Background");
            Component *d = new Dustbin("Dust bin");
            Component *p = new StationaryPaperBall("Stationary paper");
            Component *pb = new PowerBar("Power bar");
            Component *e = new ExitButton("Exit button");
            g->setActive();
            d->setActive();
            p->setActive();
            pb->setActive();
            e->setActive();
             this->isActiveComponent = false;
            Components.push_back(g);
            Components.push_back(d);
            Components.push_back(p);
            Components.push_back(pb);
            Components.push_back(e);
            return (false);
        }

        if (r->x >= 400 && r->x <= 550 && r->y >= 270 && entryflag)
        {

            SDL_RenderCopy(renderer, texture, NULL, r);
            ComponentManager::t[1] = SDL_GetTicks();
            win = true;
            int i;
            for (i = 0; i < Components.size(); i++)
            {
                Components[i]->setInactive();
            }
            Component *win = new Winner("winner");
            Component *db = new ExitButton("exitbutton");
            win->setActive();
            db->setActive();
            Components.push_back(win);
            Components.push_back(db);
            return (true);
        }
        SDL_RenderCopy(renderer, texture, NULL, r);

        count++;
    }
    return (true);
}