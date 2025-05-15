#include <vector>
#include <iostream>


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

class Object{
    public:
        std::string type;
        std::pair<int, int> loc;
    public:
        void print_type(){
            Logger::info("Type: " + type);
        }
        virtual ~Object() {}
};

class Resource : public Object {
    public:
        std::string resource_type;
        int amount;
        Resource(std::string resource_type = "default", std::pair<int,int> loc = std::make_pair(0,0), int amount = 1){
            this->amount = amount;
            this->loc = loc;
            this->type = "Resource";
            this->resource_type = resource_type;
        }
        ~Resource(){
            Logger::warn("Resource deleted");
        }
};

class Character : public Object {
    public:
        Character(std::pair<int,int> loc = std::make_pair(0, 0)){
            this->loc = loc;
            this->type = "Character";
        }
        ~Character(){
            Logger::warn("Character deleted");
        }
};

class Spawner{
    public:
        int width;
        int height;
        std::string type;
        std::string spawn_type;
        std::vector<Object*> Objects;

        void print_type(){
            Logger::info("Spawnner Type: " + type);
        }
    public:
        virtual std::pair<int, int> spawn_loc() {}
        virtual void spawn() {}
        virtual ~Spawner() {}
};

class UniformSpawner : public Spawner {
    public:
        UniformSpawner(std::string spawn_type = "Resource", int height = 100, int width = 100){
            this->width = width;
            this->height = height;
            this->spawn_type = spawn_type;
            this->type = "UniformSpawner";
        }

        std::pair<int, int> spawn_loc(){
            std::pair<int, int> loc = std::make_pair(this->width *(double)rand() / RAND_MAX, this->height * (double)rand() / RAND_MAX);
            return loc;
        }

        void spawn(){
            std::pair<int, int> loc = spawn_loc();
            if (this->spawn_type == "Resource"){
                Resource * r = new Resource("default", loc, 1);
                Logger::info("Spawned resource at: " + std::to_string(loc.first) + ", " + std::to_string(loc.second));
                this->Objects.push_back(r);
            }
            else if (this->spawn_type == "Character"){
                Character * c = new Character(loc);
                Logger::info("Spawned character at: " + std::to_string(loc.first) + ", " + std::to_string(loc.second));
                this->Objects.push_back(c);
            }
            else{
                Logger::warn("Unknown spawn type");
            }
        }

        ~UniformSpawner(){
            for (Object* object : Objects){
                delete object;
            }
            Logger::warn("UniformSpawner deleted");
        }
};
