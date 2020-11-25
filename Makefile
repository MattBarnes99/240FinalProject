CC = g++
LD = $(CC)
CCFLAGS = -std=c++17 -Wall 

EXECS = testAnimator TrafficLightTester Simulator
OBJS = testAnimator.o Animator.o VehicleBase.o Section.o Simulation.o Vehicle.o Clock.o Lane.o Intersection.o TrafficLight.o 

all: $(EXECS)

testAnimator: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
