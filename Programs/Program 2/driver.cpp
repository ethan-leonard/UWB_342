#include <iostream>
#include <cstdlib>
#include "greedyRobot.h"

int main(int argc, char* argv[]) {

    int max_distance = std::stoi(argv[1]);
    int xrob = std::stoi(argv[2]);
    int yrob = std::stoi(argv[3]);
    int xtres = std::stoi(argv[4]);
    int ytres = std::stoi(argv[5]);

    GreedyRobot robot(max_distance, xrob, yrob, xtres, ytres);
    robot.findPaths();
    std::cout << robot;

    return 0;
}