#include "greedyRobot.h"
#include <iostream>
#include <sstream>

// Constructor
GreedyRobot::GreedyRobot(int max_distance, int xrob, int yrob, int xtres, int ytres)
    : max_distance_(max_distance), xrob_(xrob), yrob_(yrob), xtres_(xtres), ytres_(ytres) {}

// Public function to find paths
void GreedyRobot::findPaths() {
    findPathsPriv(xrob_, yrob_, "", 0, ' ');
}

// Private recursive function to find paths
void GreedyRobot::findPathsPriv(int xrob, int yrob, std::string path, int last_move_count, char last_move) {
    if (xrob == xtres_ && yrob == ytres_) {
        paths_.push_back(path);
        return;
    } if (yrob < ytres_ && (last_move != 'N' || last_move_count < max_distance_)) {
        findPathsPriv(xrob, yrob + 1, path + "N", (last_move == 'N') ? last_move_count + 1 : 1, 'N');
    } if (yrob > ytres_ && (last_move != 'S' || last_move_count < max_distance_)) {
        findPathsPriv(xrob, yrob - 1, path + "S", (last_move == 'S') ? last_move_count + 1 : 1, 'S');
    } if (xrob < xtres_ && (last_move != 'E' || last_move_count < max_distance_)) {
        findPathsPriv(xrob + 1, yrob, path + "E", (last_move == 'E') ? last_move_count + 1 : 1, 'E');
    } if (xrob > xtres_ && (last_move != 'W' || last_move_count < max_distance_)) {
        findPathsPriv(xrob - 1, yrob, path + "W", (last_move == 'W') ? last_move_count + 1 : 1, 'W');
    }
}

// Getters
std::string GreedyRobot::getRobCord() const {
    std::string robCord = "(" + std::to_string(xrob_) + ", " + std::to_string(yrob_) + ")";
    return robCord;
}

std::string GreedyRobot::getTresCord() const {
    std::string tresCord = "(" + std::to_string(xtres_) + ", " + std::to_string(ytres_) + ")";
    return tresCord;
}

// Setters
void GreedyRobot::setRobCord(int x, int y) {
    xrob_ = x;
    yrob_ = y;
}

void GreedyRobot::setTresCord(int x, int y) {
    xtres_ = x;
    ytres_ = y;
}

// Overload the << operator
std::ostream& operator<<(std::ostream& os, const GreedyRobot& robot) {
    for (const std::string& path : robot.paths_) {
        os << path << std::endl;
    }
    os << "Number of paths: " << robot.paths_.size() << std::endl;
    return os;
}