#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "logger.hpp"
const std::string WARN_COLOR = "\033[1;33m";
const std::string ERROR_COLOR = "\033[1;31m";
const std::string INFO_COLOR = "\033[1;32m";
const std::string PROGRESS_COLOR = "\033[1;34m";
const std::string RESET_COLOR = "\033[0m";

std::string get_curr_time_stamp(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return std::to_string(1900 + ltm->tm_year) + "-" + std::to_string(1 + ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);
}
void Logger::init (std::string filename, bool verbose){
    Logger::file.open(filename, std::ios::app);
    Logger::verbose = verbose;
    if (Logger::verbose){
        Logger::info("Logger has been initiated in verbose mode.");
    }
}

void Logger::info(std::string message){
    Logger::file << "[" << get_curr_time_stamp() << "]" << " [INFO] [" << message << "]" << std::endl;
    if (Logger::verbose){
        std::cout << INFO_COLOR << "[INFO] " << message << RESET_COLOR << std::endl;
    }
}
void Logger::error(std::string message){
    Logger::file << "[" << get_curr_time_stamp() << "]" << " [ERROR] [" << message << "]" << std::endl;
    if (Logger::verbose){
        std::cout << ERROR_COLOR << "[ERROR] " << message << RESET_COLOR << std::endl;
    }
}
void Logger::warn(std::string message){
    Logger::file << "[" << get_curr_time_stamp() << "]" << " [WARN] [" << message << "]" << std::endl;
    if (Logger::verbose){
        std::cout << WARN_COLOR << "[WARN] " << message << RESET_COLOR << std::endl;
    }
}
void Logger::progress(std::string message){
    Logger::file << "[" << get_curr_time_stamp() << "]" << " [PROGRESS] [" << message << "]" << std::endl;
    if (Logger::verbose){
        std::cout << PROGRESS_COLOR << "[PROGRESS] " << message << RESET_COLOR << std::endl;
    }      
}
void Logger::close(){
    if (Logger::verbose){
        Logger::info("Log file has been written.");
    }
    Logger::file.close();
}