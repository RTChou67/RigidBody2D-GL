#include <iostream>
#include "physics/ball.hpp"
#include "physics/world.hpp"

int main()
{
    World world;
    world.set_size(800, 600);
    world.set_gravity(0, -9.8);

    // Add two balls with random properties
    world.add_random_Balls(4, vec2{-100, -100}, vec2{100, 100}, 1, 5, 5, 10);

    // Simulation
    for (int frame = 0; frame < 1000; ++frame)
    {
        world.print_state();
        world.simulate(1);
    }
}