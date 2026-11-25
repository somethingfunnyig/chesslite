#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>




// where we actually do stuff
int main()
{
    // make sure it gets to main
    std::cout << "Hello World!";
    // 1. Create the window (SFML 3 VideoMode takes an initializer list)
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "glup | one can only hope");
    window.setFramerateLimit(120);


    // skybox/background: black, white particles
    // create board first (labyrinth? idk)
    // procedurally generated; like shattered pixel dungeon (chess dungeon?)
    // art..... gg. pixel or hi-fidelity?
    // piece rules, then skillset (skill tree? idek)
    // decorations, interactables, items, (lore?), quests (?)
    //



    // spawn enemy pieces (both enemy and static pieces?)



    return 0;
}