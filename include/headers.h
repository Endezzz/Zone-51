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
    public:
        NLO(int InitX, int InitY);
        ~NLO();
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
        void DrawCabin() override;
        void DrawAlien() override;
        void DrawWindow() override;
};

class GreenNLO : public NLO {
    public:
        GreenNLO(int InitX, int InitwY);
        ~GreenNLO();
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
};

class Charge : public Rocket {
    public:
        Charge();
        ~Charge();
        virtual void Draw();
        void Show() override;
        void Hide() override;
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
        int size;
    public:
        Window();
        ~Window();
};

class LevelsWindow : public Window {

};

class FirstLevelWindow : public LevelsWindow {

};

class SecondLevelWindow : public FirstLevelWindow {

};

class ThirdLevelWindow : public SecondLevelWindow {

};