# 240FinalProject

## Authors:
Matt Barnes, Christ Athiogbey, Katie Wall, Megan Doran

## Compilation and Running:
To compile on the mathcs0# linux machines use - make

To run - ./simulation [input file] [initial seed]

Press enter to increment simulation to next clock tick.

## Design Decisions:

### Preprocessing:
Included setting up a configuration parser and random numbe generator. 

#### ConfigParser:
Config parser reads in the input file and assigs all parameters to a string, string map. 

Methods:
* Getter for an entry corresponding to its key

#### randomGen:
randomGen sets up a sudo random number generator.

Methods:
* setSeed is used to set the initial seed
* getter for a uniformly distributed double [0,1]. 

### Vehicles:
The primary class is VehicleBase. Vehicles store their size, direction, type, if they will turn right, as well as a section pointer to the head and tail section they occupy. The three types of vehicles are car, suv, and truck with size 2, 3, and 4, respectively.

Methods:
* Getters for vehicle ID, Direction, Size, TurnChoice, Head, and Tail
* Setters for the Direction, TurnChoice, Head, and Tail

### Road:
The primary classes to construct a road are Lane, Section, Intersection, and TrafficLight

#### Section:
Section, similarly to a doubly linked list, contains a Section* to the next and previous Section. Section's also contain an occupied boolean to signify if a vehicle is there, and a VehicleBase* to be set to a vehicle.

Methods:
* Getters for next and previous section, name, vehicle, and occupied
* Setters for next and previous section, vehicle, and occupied

#### Intersection: (Inherits from Section)
Intersections are sections that have a Section pointer to their North, South, East, and West section. Used to link the four roads together.

Methods:
* Getters and Setters for each N,S,E,W Section*.

#### Lane:
Lane contains a vector of Section pointers and the move logic for all vehicles. Each Lane contains a Section pointer to the start of its inbounds sections. Inbounds sections are the sections that will appear on the animator. There are four offbounds sections at both the beginning and end of each lane. Lanes also contain pointers to their two Intersection sections, their Direction, the total size of the lane, and the number of sections before the intersection.

Methods:
* Getter for the start Section, the size, the Direction of the lane, and the vector of VehicleBase pointers needed for the animator. 
* advanceOne moves all vehicles in a lane that are after the intersection
* advanceTwo moves all vehicles in a lant that are before the intersection
* move is helper method called by advanceOne and Two and checks where the vehicle is in the lane as well as the state of the light. Calls other helper methods, moveForward and turn depending on turn conditions
* resetMoveBool() resets the alreadyMoved boolean for every vehicle in a lane. Needed, because sometimes a vehicle could be moved two spaces if called by two different Lanes. 
* openSpace checks the start Section to see if there is an open space available for a new vehicle to be generated
* placeVehicle will place the new vehicle in the Lane, beginning in the start Section. 

#### TrafficLight:
TrafficLight stores the current LightColor, the length of each color, and the time left for each color.

Methods:
* Getter for current color and the time left for a yellow light.
* decrement decreases the current time left for the color and shifts to the next color when the time left hits 0. 

### Simulation:
Simulation is the main file for the traffic simulation. It controls the whole simulation. Combines all files to run. Contains an instance variable for each input parameter. 

Methods:
* run is the primary method of the simulation. The animator is initialized, along with four lanes, the two traffic lights created, and the intial vehicle vectors set for the animation. The randomGen seed is set, followed by a for loop that makes new vehicles for the lanes, updates the animators lights, updates the animators vehicle placements, moves traffic, and updates the traffic lights. the loop runs until the maximum input time is reached. 
* makeVehicle is called from run to possibly instantiate a new vehicle to a given lane. Decides if a vehicle will spawn, as well as what type and if the vehicle will turn.

## Restrictions:
The input file will need to be in the same folder as all the files.

Because left turns are not implemented, if probabilites for a left turn are included in the input file
that probability will be summed with the probability of a right turn. The remainder (1-rightTurn-leftTurn),
will be the probability a given vehicle goes straight.
