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
        ABC_Object(int InitX, int InitY);
        ~ABC_Object();
        bool isActive();
};

class Rocket : public ABC_Object {
    protected:
        int direction;
    public:
        Rocket(int InitX, int InitY);
        ~Rocket();
        int GetDirection();
        void SetDirection(int NewDirection);
        void Show() override;
        void Hide() override;
};

class Charge : public Rocket {
    protected:
        int radius;
    public:
        Charge(int InitX, int InitY);
        ~Charge();
        int GetRadius();
        void SetRadius(int NewRadius);
        void Show() override;
        void Hide() override;
};

class Meteor : public Charge {
    public:
        Meteor(int InitX, int InitY);
        ~Meteor();
        void Show() override;
        void Hide() override;
};

class DarkHole : public Meteor {
    public:
        DarkHole(int InitX, int InitY);
        ~DarkHole();
        void Show() override;
        void Hide() override;
};

class Heart : public ABC_Object {
    public:
        Heart(int InitX, int InitY);
        ~Heart();
        virtual void Draw();
        void Show() override;
        void Hide() override;
};

class Health : public Heart {
    public:
        Health(int InitX, int InitY);
        ~Health();
        void Show() override;
        void Hide() override;
};

class Shield : public Health {
    public:
        Shield(int InitX, int InitY);
        ~Shield();
        void Show() override;
        void Hide() override;
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