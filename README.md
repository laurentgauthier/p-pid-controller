# PID Controller

In this project a PID Controller is used to control the steering
of a vehicle in a driving simulator.

[//]: # (Image References)

[image01]: ./images/pid-controller.png "PID Controller"

## Requirements

This project requires the Udacity Term 2 Simulator which can be downloaded
[here](https://github.com/udacity/self-driving-car-sim/releases)

It also requires the [uWebSocketIO](https://github.com/uWebSockets/uWebSockets)
library.

Here are some notes about how to build and install the proper version of the
library on an Ubuntu system:

    sudo apt-get update
    sudo apt-get install git libuv1-dev libssl-dev gcc g++ cmake make
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    mkdir build
    cd build
    cmake ..
    make
    sudo make install
    cd ../..
    sudo ln -s /usr/lib64/libuWS.so /usr/lib/libuWS.so
    sudo rm -r uWebSockets

## Other Important Dependencies

* cmake >= 3.5
* gcc/g++ >= 5.4

## Build Instructions

Once the install for uWebSocketIO is complete, the main program can be built
and run by doing the following from the project top directory.

1. Clone this repository
2. mkdir build
3. cd build
4. cmake ..
5. make

## How to Run

### Start the simulator

Start the simulator and select the EKF scenario in the simulator:

    ./term2_sim_linux/term2_sim.x86_64

### Run the PID Controller

The executable can then be started:

    ./pid

Once this is done just press the "Start" button in the simulator and
watch the fireworks.

### How it Works

The PID executable is using a simple protocol using uWebSocketIO to
communicate with the simulator exchanging JSON-formatted messages.

INPUT: values provided by the simulator to the c++ program

* ["cte"] => the cross track error as reported by the simulator
* ["speed"] => the speed of the vehicle as reported by the simulator
* ["steering_angle"] => the steering angle as reported by the simulator


OUTPUT: values provided by the c++ program to the simulator

* ["steering_angle"] <= the steering command as computed by the PID controller
* ["throttle"] <= set to a constant value of 0.3 in our experiments

## Discussion

### PID Parameter Tuning

The PID controller parameters were tuned manually, using the principles of the twiddle
approach described in the training material.

The following parameter values have successfully been used to complete a full circuit:

* P = 0.11
* I = 0.001
* D = 3.2

### Some Observations

Before applying a more methodic approach in order to find working parameters I made
some naive experiments to gain some practical insights on the effect of the parameters:

* First I started by setting only the P parameter, and while it was somehow efficient at controlling
  the vehicle there were major oscillations in the system, and the vehicle was out of control
  by the first serious bend in the road.
* In a second phase it was possible to somewhat control the oscillations using the D parameter.

But in order to PID parameters that would allow to meet the spec it was necessary to get a more
systematic approach.

There are still at times during the circuit where some oscillations are observed, and despite
my best effort I could not get rid of them all.


### Results

Here is a screenshot of the simulation results:

![test result][image01]
