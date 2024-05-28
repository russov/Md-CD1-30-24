#pragma once


class Figure
{
public:
    virtual ~Figure() = default;
    virtual void display() const = 0;
};

class Ball : public Figure {
public:
    void display() const override;
};

class Cylinder : public Figure {
public:
    void display() const override;
};

class Pyramid : public Figure {
public:
    void display() const override;
};

