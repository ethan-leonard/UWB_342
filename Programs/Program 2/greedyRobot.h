#ifndef GREEDY_ROBOT_H
#define GREEDY_ROBOT_H

#include <vector>
#include <string>
#include <ostream>

class GreedyRobot {
    private:
        void findPathsPriv(int xrob, int yrob, std::string path, int last_move_count, char last_move);

        int max_distance_;
        int xrob_; 
        int yrob_;
        int xtres_;
        int ytres_;
        std::vector<std::string> paths_;

    public:
        // Constructor 
        GreedyRobot(int max_distance, int xrob, int yrob, int xtres, int ytres);

        //Functions
        void findPaths();

        // Getters and Setters
        std::string getRobCord() const;
        std::string getTresCord() const;

        void setRobCord(int x, int y);
        void setTresCord(int x, int y);

        // Friend function to overload the << operator
        friend std::ostream& operator<<(std::ostream& os, const GreedyRobot& robot);
};

#endif