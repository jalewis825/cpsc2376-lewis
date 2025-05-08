#pragma once

#include <string>
#include <memory>

// Abstract Strategy
class AttackStrategy {
public:
    virtual int execute() const = 0;
    virtual ~AttackStrategy() = default;
};

// Concrete Strategies
class DrillAttack : public AttackStrategy {
public:
    int execute() const override;
};

class LaserAttack : public AttackStrategy {
public:
    int execute() const override;
};

// Robot Class
class Robot {
private:
    std::string name;
    int hitPoints;
    std::unique_ptr<AttackStrategy> strategy;

public:
    Robot(const std::string& name, std::unique_ptr<AttackStrategy> strategy);

    int attack();
    void takeDamage(int amount);
    bool isAlive() const;
    const std::string& getName() const;
    int getHP() const;
};