#ifndef BIRD_H_
#define BIRD_H_

#include "string"

class Bird {
    private:
        std::string name_;
        int id_;
    public:
        Bird();

        void set_name(std::string name) {
            name_ = name;
        }

        void set_id(int id) {
            id_ = id;
        }

};
#endif