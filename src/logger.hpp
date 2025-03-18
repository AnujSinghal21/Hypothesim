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
