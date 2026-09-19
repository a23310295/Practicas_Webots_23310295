#include <webots/Robot.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/Motor.hpp>
#include <iostream>

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace std;
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();

  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
    Motor *motor = robot->getMotor("MOTOR");
    motor->setPosition(INFINITY);
    motor->setForce(0);
    PositionSensor *ps = robot->getPositionSensor("ENCODER");
    ps->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
      double val = ps->getValue();
      cout<<"posicion actual: "<< val <<endl;

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
     
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
