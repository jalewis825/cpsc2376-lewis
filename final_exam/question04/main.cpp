/*Robotics Arena Duel
Your Task:

Create an abstract base class AttackStrategy with virtual int execute() const = 0;.
Two strategies:
DrillAttack: Fixed attack power of 15.
LaserAttack: Random attack power between 5 and 25.
Alternatively, implement the strategies using std::function<int()>.
Create a Robot class with a name, 100 hit points, and either a smart pointer to an AttackStrategy or std::function<int()>.
Simulate a 1v1 duel that runs until one or both robots end up with 0 hit points.

AI: used to help me with the random syntax and to give me some robot names. Used it to try and figure out why hp wasn't doing right for beta but ran out of time.
I found the error after I ran out of time...it was in line 41....*face palm** I wrote beta.attack() instead of beta.getHP()
*/

#include <iostream>
#include "robot_duel.h"

int main()
{
    Robot alpha("Aegis-7", std::make_unique<DrillAttack>()); 
    Robot beta("NOVA-X", std::make_unique<LaserAttack>());
    
    int round = 1;

    std::cout << "===ROBOT ARENA DUEL START===" << std::endl;

    while (alpha.isAlive() && beta.isAlive()) {
        std::cout << "\n-- Round " << round++ << " --" << std::endl;
        
        int alphaHit = alpha.attack();
        int betaHit = beta.attack();

        std::cout << alpha.getName() << " attacks for " << alphaHit << std::endl;
        std::cout << beta.getName() << " attacks for " << betaHit << std::endl;

        beta.takeDamage(alphaHit);
        alpha.takeDamage(betaHit);

        std::cout << std::endl;
        std::cout << alpha.getName() << " HP: " << alpha.getHP() << std::endl;
        std::cout << beta.getName() << " HP: " << beta.getHP() << std::endl;
    }

    std::cout << "\n=== DUEL OVER ===" << std::endl;

    if (alpha.isAlive() && !beta.isAlive()) {
        std::cout << alpha.getName() << " wins!" << std::endl;
    }
    else if (beta.isAlive() && !alpha.isAlive()) {
        std::cout << beta.getName() << " wins!" << std::endl;
    }
    else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}
