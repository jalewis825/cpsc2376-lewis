#include "robot_duel.h"
#include <iostream>
#include <random>

int DrillAttack::execute() const {
    return 15;
};

int LaserAttack::execute() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(5, 25);
    return dist(gen);
};


Robot::Robot(const std::string& name, std::unique_ptr<AttackStrategy> strategy)
    : name(name), hitPoints(100), strategy(std::move(strategy)) {}

int Robot::attack() {
    return strategy->execute();
}

void Robot::takeDamage(int amount) {
    if (hitPoints > 0) {
        hitPoints -= amount;
    }
    if (hitPoints < 0) hitPoints = 0;
}

bool Robot::isAlive() const {
    return hitPoints > 0;
}

const std::string& Robot::getName() const {
    return name;
}

int Robot::getHP() const {
    return hitPoints;
}