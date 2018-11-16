#ifndef FUNWITHKRLE_PLAYER_H
#define FUNWITHKRLE_PLAYER_H
#include <string>

class Player {

private:
    std::string name;
public:
    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //FUNWITHKRLE_PLAYER_H
