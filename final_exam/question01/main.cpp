/*Museum Security System
Your Task:

Create a base class Sensor with a pure virtual method trigger().
Create three derived classes: MotionSensor, GlassBreakSensor, and ThermalSensor.
Each trigger() should print a unique alert message appropriate to that sensor.
In main(), create a std::vector<std::unique_ptr<Sensor>> containing different sensors.
Loop through the vector and call trigger() on each.

AI: I couldn't remember "std::make_unique" to add the different sensors to the vector. I used AI to help me there.*/

#include <iostream>
#include <vector>
#include <memory>

//Base Class
class Sensor {
public:
    virtual void trigger() const = 0;
    virtual ~Sensor() = default;
};

//Derived Classes
class MotionSensor : public Sensor {
public:
    void trigger() const override {
        std::cout << "Motion sensor activated! Alerting security personnel." << std::endl;
    }
};

class GlassBreakSensor : public Sensor {
public:
    void trigger() const override {
        std::cout << "Glass break sensor activated! Alerting security personnel." << std::endl;
    }
};

class ThermalSensor : public Sensor {
public:
    void trigger() const override {
        std::cout << "Thermal sensor activated! Alerting security personnel." << std::endl;
    }
};

int main()
{
    std::vector <std::unique_ptr<Sensor>> sensors;

    //adds the different sensors to the vector
    sensors.push_back(std::make_unique<MotionSensor>());
    sensors.push_back(std::make_unique<GlassBreakSensor>());
    sensors.push_back(std::make_unique<ThermalSensor>());

    for (const auto& sensor : sensors) {
        sensor->trigger();
    }

    return 0;
}