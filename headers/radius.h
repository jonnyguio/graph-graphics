class Radius {
    private:
        float radius;
        float rate;

    public:
        Radius();

        Radius(float, float);

        float getRadius();

        float increase();

        float Rate();

        void Rate(float);

        bool isTouching();
};
