#include <iostream>
#include "physics/ball.hpp"
#include "physics/world.hpp"

int main()
{
    World world;
    world.set_size(800, 600);
    world.set_gravity(0, -9.8);

    // Add two balls
    Ball ball1, ball2;

    ball1.set_position(10, 10);
    ball2.set_position(20, 20);

    ball1.set_size(5);
    ball2.set_size(5);

    ball1.set_velocity(3, 2);
    ball2.set_velocity(2, 3);

    ball1.set_mass(1);
    ball2.set_mass(2);

    // configuration
    world.add_Ball(std::move(ball1));
    world.add_Ball(std::move(ball2));

    // Simulation
    for (int frame = 0; frame < 7800; ++frame)
    {
        world.print_state();
        world.simulate(1);
    }
}