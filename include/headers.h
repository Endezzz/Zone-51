#pragma once
extern HDC hdc;
class Point {
    protected:
        int x;
        int y;
        bool visible;
    public:
        Point(int InitX, int InitY);
        ~Point();
        int GetX();
        int GetY();
        bool GetVisible();
        void SetX(int NewX);
        void SetY(int NewY);
        void SetVisible(bool NewVisible);
        virtual void Show();
        virtual void Hide();
        void MoveTo(int NewX, int NewY);
};

class NLO : public Point {
    protected:
        int height = 90;
        int width = 180;
    public:
        NLO(int InitX, int InitY);
        ~NLO();
        int GetHeight();
        int GetWidth();
        void Show() override;
        void Hide() override;
        virtual void DrawCabin();
        virtual void DrawAlien();
        virtual void DrawWindow();
};

class YellowNLO : public NLO {
    public:
        YellowNLO(int InitX, int InitY);
        ~YellowNLO();
        void DrawWindow() override;
        void DrawAlien() override;
        void DrawCabin() override;
};

class RedNLO : public NLO {
    public:
        RedNLO(int InitX, int InitwY);
        ~RedNLO();
        void DrawCabin() override;
        void DrawAlien() override;
        void DrawWindow() override;
};

class ABC_Object : public Point {
    protected:
        bool active;
    public:
        ABC_Object();
        ~ABC_Object();
        bool isActive();
        void Active();
        void Disactive();
};

class Rocket : public ABC_Object {
    public:
        Rocket();
        ~Rocket();
        void Show() override;
        void Hide() override;
        virtual void Draw();
};

class Charge : public Rocket {
    public:
        Charge();
        ~Charge();
        void Draw() override;
};

class Meteor : public Charge {
    public:
        Meteor();
        ~Meteor();
        void Draw() override;
};

class DarkHole : public Meteor {
    public:
        DarkHole();
        ~DarkHole();
        void Draw() override;
};

class Heart : public ABC_Object {
    public:
        Heart();
        ~Heart();
        virtual void Draw();
        void Show() override;
        void Hide() override;
};

class Health : public Heart {
    public:
        Health();
        ~Health();
        void Draw() override;
};

class Shield : public Health {
    public:
        Shield();
        ~Shield();
        void Draw() override;
};

class Window : public Point {
    protected:
        int state = 1;
        int height = 700;
        int width = 1200;
    public:
        Window(int InitX, int InitY);
        ~Window();
        int GetState();
        void SetState(int NewState);
};

class LevelsWindow : public Window {
    public:
        LevelsWindow(int InitX, int InitY);
        ~LevelsWindow();
        void Show() override;
        void Hide() override;
};

class FirstLevelWindow : public LevelsWindow {
    public:
        FirstLevelWindow(int InitX, int InitY);
        ~FirstLevelWindow();
        void Show() override;
        void Hide() override;
};

class SecondLevelWindow : public FirstLevelWindow {
    public:
        SecondLevelWindow(int InitX, int InitY);
        ~SecondLevelWindow();
        void Show() override;
        void Hide() override;
};

class ThirdLevelWindow : public SecondLevelWindow {
    public:
        ThirdLevelWindow(int InitX, int InitY);
        ~ThirdLevelWindow();
        void Show() override;
        void Hide() override;
};