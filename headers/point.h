class Point {
    private:
        float x, y;

    public:
        Point (float, float);
        Point ();

    public:
        void print(void);

        float distance(Point*);

        float X();

        float Y();

        void X(float x);

        void Y(float y);
};
