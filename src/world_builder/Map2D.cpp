#include <vector>

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
    private:
    static std::ofstream file;
    static bool verbose;
    public: 
    static void init(std::string filename, bool verbose);
    static void info(std::string message);
    static void error(std::string message);
    static void warn(std::string message);
    static void progress(std::string message);
    static void close();
};
#endif

#include "../world_builder/ObjectSpawnner.cpp"

class Map2D{
    public:
        int width;
        int height;
        std::string type;
        std::vector<std::pair<std::string, int> > spawn_types;
        std::vector<Spawner*> spawners;
    public:
        Map2D(int height = 100, int width = 100, std::vector< std::pair<std::string, int> > spawn_types = {std::make_pair("Resource", 10), std::make_pair("Character", 10)} ){
            this->width = width;
            this->height = height;
            this->type = "Map2D";
            this->spawn_types = spawn_types;
            Logger::info("Map2D created with height: " + std::to_string(height) + " and width: " + std::to_string(width));
        }

        void populate(){
            
            for (std::pair<std::string, int> spawn_type : this->spawn_types){
                if (spawn_type.first == "Resource"){
                    spawners.push_back(new UniformSpawner(spawn_type.first, height, width));
                    for (int i = 0; i < spawn_type.second; i++){
                        spawners.back()->spawn();
                    }
                }
                else if (spawn_type.first == "Character"){
                    spawners.push_back(new UniformSpawner(spawn_type.first, height, width));
                    for (int i = 0; i < spawn_type.second; i++){
                        spawners.back()->spawn();
                    }
                }
                else{
                    Logger::error("Unknown spawn type: " + spawn_type.first);
                }
            }
        }

        ~Map2D(){
            for (Spawner* spawner : spawners){
                delete spawner;
            }
            Logger::warn("Map2D deleted");
        }
};