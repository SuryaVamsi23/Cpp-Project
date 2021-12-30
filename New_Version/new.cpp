#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
int max_velocity = 140;
bool level2 = false;
int velocity;
using namespace std;

class Mouse
{
public:
    int get_mouse_x()
    {
        SDL_GetMouseState(&x_coordinate, &y_coordinate);
        return (x_coordinate);
    }

    int get_mouse_y()
    {
        SDL_GetMouseState(&x_coordinate, &y_coordinate);
        return (y_coordinate);
    }

    bool isclicked()
    {
        Uint32 cursors = SDL_GetMouseState(&x_coordinate, &y_coordinate);

        if ((cursors & SDL_BUTTON_LMASK) != 0)
        {
            return true;
        }

        return false;
    }

private:
    int x_coordinate;
    int y_coordinate;
};

class Button
{
public:
    Button(int x, int y, int h, int w, string s)
    {
        r = new SDL_Rect();
        x_cordinate = x;
        y_cordinate = y;
        width = w;
        height = h;
        content = s;
    }

    void place_button(SDL_Renderer *renderer)
    {
        s = IMG_Load(content.c_str());
        t = SDL_CreateTextureFromSurface(renderer, s);
        SDL_FreeSurface(s);
        r->x = this->x_cordinate;
        r->y = this->y_cordinate;
        r->h = this->height;
        r->w = this->width;
        SDL_RenderCopy(renderer, t, NULL, r);
    }

    bool cursor_on_button(Mouse *m)
    {
        int mouse_x = m->get_mouse_x();
        int mouse_y = m->get_mouse_y();

        if ((mouse_x > this->x_cordinate) && (mouse_x < this->x_cordinate + this->width))
        {
            if ((mouse_y > this->y_cordinate) && (mouse_y < this->y_cordinate + this->height))
            {
                return true;
            }

            return false;
        }
        return false;
    }

    bool isclicked(Mouse *m)
    {
        if (this->cursor_on_button(m) && m->isclicked())
        {
            return true;
        }

        return false;
    }

    int get_x_coordinate()
    {
        return (x_cordinate);
    }

    int get_y_coordinate()
    {
        return (y_cordinate);
    }

private:
    SDL_Surface *s;
    SDL_Texture *t;
    SDL_Rect *r;
    int x_cordinate;
    int y_cordinate;
    int width;
    int height;
    string content;
};

class Component
{
public:
    bool isActiveComponent;
    SDL_Surface *surface;
    SDL_Texture *texture;
    Component()
    {
        isActiveComponent = false;
    }
    void setActive()
    {
        isActiveComponent = true;
    }
    void setInactive()
    {
        isActiveComponent = false;
    }
    virtual void handleEvents() = 0;
    virtual void update(vector<Component *> &Components, bool *isRunning) = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
};

class MainBackground : public Component
{
public:
    void handleEvents()
    {
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            surface = IMG_Load("main.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
        }
    }
};

class ExitButton : public Component
{
public:
    ExitButton() : Component()
    {
        exit_button = new Button(720, 5, 60, 60, "exit.png");
        mouse = new Mouse;
        isClicked = false;
    }
    void handleEvents()
    {
        if (isActiveComponent)
        {
            if (exit_button->isclicked(mouse))
            {
                isClicked = true;
            }
        }
        //cout << isClicked << endl;
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
        if (isClicked == true)
        {
            int i;
            for (i = 0; i < Components.size(); i++)
            {
                Components[i]->setInactive();
            }
            isClicked = false;
            *isRunning = false;
        }
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            exit_button->place_button(renderer);
        }
    }

private:
    Button *exit_button;
    Mouse *mouse;
    bool isClicked;
};

class Game_Background : public Component
{
public:
    void handleEvents()
    {
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            surface = IMG_Load("room.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
        }
    }
};

class Dustbin : public Component
{
public:
    Dustbin() : Component()
    {
        r = new SDL_Rect();
    }
    void handleEvents()
    {
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            surface = IMG_Load("dustbin.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            r->x = 600;
            r->y = 320;
            r->w = 150;
            r->h = 100;
            SDL_RenderCopy(renderer, texture, NULL, r);
        }
    }

private:
    SDL_Rect *r;
};

class StationaryPaperBall : public Component
{
public:
    StationaryPaperBall() : Component()
    {
        r = new SDL_Rect();
        r->x = 0;
        r->y = 370;
        r->w = 50;
        r->h = 50;
    }
    void handleEvents()
    {
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            surface = IMG_Load("paper.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, NULL, r);
        }
    }

private:
    SDL_Rect *r;
};

class MovingPaperBall : public Component
{
public:
    MovingPaperBall() : Component()
    {
        r = new SDL_Rect();
        r->x = 0;
        r->y = 370;
        r->w = 50;
        r->h = 50;
        startTime = SDL_GetTicks();
    }
    void handleEvents()
    {
    }

    void update(vector<Component *> &Components, bool *isRunning)
    {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 timeElapsed = currentTime - startTime;
        isActiveComponent = true;
        //employ physics engine.
        //change r->x and r->y according to time elapsed
        float in_radian = 45*3.14159/180;
        int time_of_flight = (2*velocity*sin(in_radian)/10);
        if(count<time_of_flight){
            r->x = velocity*cos(in_radian)*count;
            r->y = 370 - ((velocity*sin(in_radian)*count) - (5*count)*(count));
        }
        else{
            r->x = velocity*cos(in_radian)*time_of_flight;
            r->y = 370;
        }
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            surface = IMG_Load("paper.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, NULL, r);
            if(r->x>=600 && r->x<=750)
                level2 = true;
            count++;

        }
    }

private:
    SDL_Rect *r;
    Uint32 startTime;
    int count = 1;
};

class AngleBar : public Component
{
public:
    AngleBar() : Component()
    {
        startTime = SDL_GetTicks();
        mouse = new Mouse;
        isClicked = false;
        r = new SDL_Rect();
        r->x = 450;
        r->y = 390;
        r->w = 100;
        r->h = 75;
        AngleBarButton = new Button(r->x, r->y, r->h, r->w, "AngleBar.png");
    }
    void handleEvents()
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
    void update(vector<Component *> &Components, bool *isRunning)
    {
        Uint32 CurrentTime = SDL_GetTicks();
        /*
        Over here write the code for source rectangle for angle bar. This way we can animate angle bar
        */
        if (isClicked == true)
        {
            cout << "Start Time:- " << startTime << " End Time:- " << endTime << endl;
            Components[Components.size() - 1]->setInactive();
            Components[Components.size() - 4]->setInactive();
            isClicked = false;
            Component *mb = new MovingPaperBall();
            mb->setActive();
            Components.push_back(mb);
        }
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            Uint32 currentTime = SDL_GetTicks();
            //find good picture of angle bar. this is a dummy picture
            surface = IMG_Load("AngleBar.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture,NULL , r);
        }
    }

private:
    SDL_Rect *r;
    Uint32 startTime;
    Uint32 endTime;
    Button *AngleBarButton;
    Mouse *mouse;
    bool isClicked;
};

class PowerBar : public Component
{
public:
    PowerBar() : Component()
    {
        startTime = SDL_GetTicks();
        mouse = new Mouse;
        isClicked = false;
        r = new SDL_Rect();
        r->x = 150;
        r->y = 390;
        r->w = 150;
        r->h = 75;
        PowerBarButton = new Button(r->x, r->y, r->h, r->w, "PowerBar.png");
        animatePowerButton();
    }

    void animatePowerButton()
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
        rects[9].h = 18;//Render each speed level 
        rects[9].w = 162;
    }

    void handleEvents()
    {
        Uint32 CurrentTime = SDL_GetTicks();
        /*
        Over here write the code for source rectangle for power bar. This way we can animate power bar
        */

        if (isActiveComponent)
        {

            if (PowerBarButton->isclicked(mouse))
            {
                isClicked = true;
                endTime = SDL_GetTicks();

            }
        }
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
        if (isClicked == true)
        {
            cout << "Start Time:- " << startTime << " End Time:- " << endTime << endl;
            SDL_Delay(1000);
            Components[Components.size() - 2]->setInactive();
            Component *a = new AngleBar();
            a->setActive();
            Components.push_back(a);
            velocity = (max_velocity*count)/10;
            isClicked = false;
        }
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            Uint32 currentTime = SDL_GetTicks();
            surface = IMG_Load("PowerBar.png");
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, &rects[count], r);//Saketh
            count++;
            if (count == 11)
                count = 0;
        }
    }

private:
    SDL_Rect *r;
    Uint32 startTime;
    Uint32 endTime;
    Button *PowerBarButton;
    Mouse *mouse;
    SDL_Rect rects[10];
    bool isClicked;
    int AnimationTime = 10;
    int count = 0;
};

class startButton : public Component
{
public:
    startButton() : Component()
    {
        start_button = new Button(25, 240, 50, 100, "start.png");
        mouse = new Mouse;
        isClicked = false;
    }
    void handleEvents()
    {
        if (isActiveComponent)
        {
            if (start_button->isclicked(mouse))
            {
                isClicked = true;
            }
        }
        //cout << isClicked << endl;
    }
    void update(vector<Component *> &Components, bool *isRunning)
    {
        if (isClicked == true)
        {
            int i;
            for (i = 0; i < Components.size(); i++)
            {
                Components[i]->setInactive();
            }
            Component *g = new Game_Background();
            Component *d = new Dustbin();
            Component *p = new StationaryPaperBall();
            Component *pb = new PowerBar();
            Component *e = new ExitButton();
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
            isClicked = false;
        }
    }
    void render(SDL_Renderer *renderer)
    {
        if (isActiveComponent)
        {
            start_button->place_button(renderer);
        }
    }

private:
    Button *start_button;
    Mouse *mouse;
    bool isClicked;
};

class Component_Manager
{
public:
    void init()
    {
        main_window = SDL_CreateWindow("Paper Toss", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 480, 0);
        renderer = SDL_CreateRenderer(main_window, -1, 0);
        SDL_RenderClear(renderer);
    }
    void begin_game()
    {
        init();
        vector<Component *> Components;
        Component *m = new MainBackground();
        Component *s = new startButton();
        Component *e = new ExitButton();
        m->setActive();
        s->setActive();
        e->setActive();
        Components.push_back(m);
        Components.push_back(s);
        Components.push_back(e);
        bool isRunning = true;
        Mouse *mouse = new Mouse();

        const int FPS = 60;
        const int frameDelay = 1000 / FPS;

        Uint32 frameStart;
        int frameTime;

        while (isRunning)
        {
            SDL_PumpEvents();
            frameStart = SDL_GetTicks();

            SDL_RenderClear(renderer);
            int i;
            for (i = 0; i < Components.size(); i++)
            {
                Components[i]->handleEvents();
                Components[i]->update(Components, &isRunning);
                Components[i]->render(renderer);
            }
            SDL_RenderPresent(renderer);

            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < frameDelay)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
    }

private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
};

int main()
{
    Component_Manager *game = new Component_Manager();
    game->begin_game();
    return 0;
}