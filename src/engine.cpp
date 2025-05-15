#include <iostream>
#include "logger.hpp"
#include "./world_builder/Map2D.cpp"

class Engine{
    public:
    Engine(){
        // Initialize the engine
        // This could include setting up the game loop, loading resources, etc.

        std::cout << "Engine has been initiated" << std::endl;

        // Example of using the Logger class
        Logger::info("Engine started, Initializing game loop...");
        
        Map2D map;

        map.populate();
        Logger::info("Map populated with objects");
    }

    ~Engine(){
        // Clean up the engine
        std::cout << "Engine has been destroyed" << std::endl;

        // Example of using the Logger class
        Logger::info("Engine stopped");
    }
};


std::ofstream Logger::file = std::ofstream();
bool Logger::verbose = false;

int main() {
    // Create an instance of the Engine class
    Logger::init("../tmp/engine.log", true);
    Engine engine;

    return 0;
}