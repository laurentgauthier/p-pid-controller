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

* ["sensor_measurement"] => the measurement that the simulator observed (either lidar or radar)


OUTPUT: values provided by the c++ program to the simulator

* ["estimate_x"] <= kalman filter estimated position x
* ["estimate_y"] <= kalman filter estimated position y
* ["rmse_x"]
* ["rmse_y"]
* ["rmse_vx"]
* ["rmse_vy"]

## Results

Here is a screenshot of the simulation results:

![test result][image01]
