#pragma once
#include "physics/ball.hpp"
#include "physics/vec2.hpp"
#include <vector>
#include <span>

class World
{
private:
    // Size of the panel
    vec2 world_size;
    // Gravaty
    vec2 gravity;
    // Balls
    std::vector<Ball> balls;
    // Step length
    double dt;

public:
    // Constructor
    World() : dt(0.01) {}
    // Setters
    void set_size(double x = 1, double y = 1);
    void set_size(const vec2 &world_size_in);
    void set_gravity(double gx = 0, double gy = 0);
    void set_gravity(const vec2 &g);
    void add_Ball(Ball &&b);
    void add_Balls(std::vector<Ball> &&bs);
    void set_dt(double s = 0.01);
    // Getters
    const vec2 &get_size() const;
    const vec2 &get_gravity() const;
    Ball &get_Ball(size_t index);
    const Ball &get_Ball(size_t index) const;
    std::span<Ball> get_Balls(size_t start, size_t end);
    std::span<const Ball> get_Balls(size_t start, size_t end) const;
    // Trace compute step by step
    void step();
};