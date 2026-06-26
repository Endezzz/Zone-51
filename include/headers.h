class Point {
    private:
        int x;
        int y;
        bool visible;
    protected:
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
        NLO(int InitX, int InitY);
        ~NLO();
        void Show() override;
        void Hide() override;
        virtual void DrawCabin();
        virtual void DrawAlien();
        virtual void DrawWindow();
};

class YellowNLO : public NLO {
    protected:
        YellowNLO(int InitX, int InitY);
        ~YellowNLO();
        void DrawCabin() override;
        void DrawAlien() override;
        void DrawWindow() override;
};

class GreenNLO : public NLO {
    protected:
        GreenNLO(int InitX, int InitwY);
        ~GreenNLO();
        void DrawCabin() override;
        void DrawAlien() override;
        void DrawWindow() override;
};

class ABC_Object : Point {
    private:
        bool active;
    protected:
        ABC_Object();
        ~ABC_Object();
        bool isActive();
        void Active();
        void Disactive();
};

class Rocket : ABC_Object {
    protected:
        Rocket();
        ~Rocket();
        void Show() override;
        void Hide() override;
};

class Charge : Rocket {
    protected:
        Charge();
        ~Charge();
        void Show() override;
        void Hide() override;
};

class Meteor : Charge {
    protected:
        Meteor();
        ~Meteor();
        void Show() override;
        void Hide() override;
};

class DarkHole : Meteor {
    protected:
        DarkHole();
        ~DarkHole();
        void Show() override;
        void Hide() override;
};

class Heart : ABC_Object {
    protected:
        Heart();
        ~Heart();
        void Show() override;
        void Hide() override;
};

class Health : Heart {
    protected:
        Health();
        ~Health();
        void Show() override;
        void Hide() override;
};

class Shield : Health {
    protected:
        Shield();
        ~Shield();
        void Show() override;
        void Hide() override;
};