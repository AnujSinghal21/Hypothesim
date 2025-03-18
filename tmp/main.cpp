#include "../src/logger.hpp"
#include <vector>
#include <algorithm>
class Character {
    public:
    std::string type;
    int priority;
    std::pair<int, int> priority_range;
    public:
    void print_type(){
        Logger::info("Type: " + type);
    }
    virtual ~Character() {}
};

class Spawner : public Character {
    public:
    // const std::string type = "Spawner";
    Spawner(std::pair<int,int> priority_range = std::make_pair(1e8, 2e8)){
        this->type = "Spawner";
        this->priority_range = priority_range;
    }
    ~Spawner(){
        Logger::warn("Spawner deleted");
    }
};

class Agent : public Character {
    public:
    // const std::string type = "Spawner";
    Agent(std::pair<int,int> priority_range = std::make_pair(1e8, 2e8)){
        this->type = "Agent";
        this->priority_range = priority_range;
    }
    ~Agent(){
        Logger::warn("Agent deleted");
    }
};

class World {
    private:
    std::vector<Character*> characters;

    void generate_priorities(){
        for (Character * c : characters){
            c->priority = rand() % (c->priority_range.second - c->priority_range.first) + c->priority_range.first;
        }
    }
    public:

    World(){
        Logger::info("World has been initiated");
    }
    ~World(){
        for (auto c: characters){cd
            delete c;
        }
        Logger::info("World has been destroyed");
    }
    void add_character(Character * c){
        characters.push_back(c);
    }
    void simulate(int NUM_TICKS=1){
        Logger::info("Simulation has started");
        for (int tick = 1; tick <= NUM_TICKS; tick++){
            this->generate_priorities();
            std::sort(characters.begin(), characters.end(), [](Character * a, Character * b){
                return a->priority < b->priority;
            });
            for (Character * c : characters){
                c->print_type();
            }
            
        }
        Logger::info("Simulation has ended");
    }
};

std::ofstream Logger::file = std::ofstream();
bool Logger::verbose = false;

int main(){
    Logger::init("./tmp/log.txt", true);
    World * w = new World();
    Spawner * s = new Spawner();
    Agent * a = new Agent();
    w->add_character(s);
    w->add_character(a);


    w->simulate(4);
    delete w;
    Logger::close();
    return 0;
}