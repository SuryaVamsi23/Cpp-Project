#include "MovingPaperBall.hpp"
#include "PowerBar.hpp"
#include "PowerBar2.hpp"
#include "ComponentManager.hpp"
MovingPaperBall::MovingPaperBall(string s, int v, int a) : Component(s)
{
    r = new SDL_Rect();
    r->x = 0;
    r->y = 370;
    r->w = 50;
    r->h = 50;
    startTime = SDL_GetTicks();
    angle = a;
    velocity = v;
    //velocity = 14 * 6;
    //angle = 9 * 5;
    entryflag = false;

    surface = IMG_Load("paper.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void MovingPaperBall::handleEvents()
{
}
void MovingPaperBall::update(vector<Component *> &Components, bool *isRunning)
{
    Uint32 currentTime = SDL_GetTicks();
    Uint32 timeElapsed = currentTime - startTime;
    float in_radian = angle * 3.14159 / 180;
    float time_of_flight = (2 * velocity * sin(in_radian) / 10);
    float count = timeElapsed/200.0;
    r->x = velocity * cos(in_radian) * count;
    r->y = 370 - ((velocity * sin(in_radian) * count) - (5 * count) * (count));
    if(r->x > 600 && r->x < 750 && r->y >= 320 && r->y <= 335)
    {
        entryflag = true;
    }
    if(r->y>=365)
        r->y = 370;

}
bool MovingPaperBall::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        if (r->x > 750 || r->y > 370 || r->y <= 0)
        {
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
            Components.push_back(g);
            Components.push_back(d);
            Components.push_back(p);
            Components.push_back(pb);
            Components.push_back(e);
            return (false);
        }
        if (r->x != 0 && r->x < 600 && r->y == 370)
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
            Components.push_back(g);
            Components.push_back(d);
            Components.push_back(p);
            Components.push_back(pb);
            Components.push_back(e);
            return (false);
        }
        SDL_RenderCopy(renderer, texture, NULL, r);

        if (r->x >= 600 && r->x <= 750 && r->y >= 350 && entryflag)
        {

            SDL_RenderCopy(renderer, texture, NULL, r);
            Component *level2bg = new Level2("level 2");
            level2bg->setActive();


            for (int i = 0; i < Components.size(); i++)
            {
                Components[i]->setInactive();
            }
            Components.push_back(level2bg);
            Component *table = new Table("table");
            Component *exit = new ExitButton("exit");
            Component *dustbin = new Dustbin2("dustbin");
            Component *sball = new StationaryPaperBall("sball");
            Component *pbar = new PowerBar2("pbar");
            table->setActive();
            exit->setActive();
            dustbin->setActive();
            sball->setActive();
            pbar->setActive();
            Components.push_back(table);
            Components.push_back(exit);
            Components.push_back(dustbin);
            Components.push_back(sball);
            Components.push_back(pbar);
        }

        count++;
    }
    return (true);
}