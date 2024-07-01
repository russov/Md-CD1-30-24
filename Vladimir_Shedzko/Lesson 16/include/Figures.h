#ifndef FIGURES_H
#define FIGURES_H

class Figure
{
public:
    virtual float volume() const;

    bool operator == (const Figure& other);

    bool operator != (const Figure& other);
};

class Sphere : public Figure
{
public:
    Sphere();
    Sphere(const float _radius);

    virtual float volume() const override;

protected:
    float radius;
};

class Cylinder : public Sphere
{
public:
    Cylinder();
    Cylinder(const float _radius, const float _height);

    virtual float volume() const override;

protected:
    float height;
};

class Pyramid : public Cylinder
{
public:
    Pyramid();
    Pyramid(const float _radius, const float _height);

    virtual float volume() const override;
};

#endif // FIGURES_H
