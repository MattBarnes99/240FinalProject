CC = g++
LD = $(CC)
CCFLAGS = -Wall -Wno-deprecated -Werror=return-type -std=c++17 $(INCDIR) -g -c
LDFLAGS = -Wall -Wno-deprecated -Werror=return-type -std=c++17 -g

EXECS = testAnimator TrafficLightTester simulation
OBJS = Simulation.o Animator.o ConfigParser.o Intersection.o Lane.o randomGen.o Section.o TrafficLight.o VehicleBase.o

simulation: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o simulation

simulation.o: Simulation.cpp Simulation.h Animator.cpp Animator.h ConfigParser.cpp ConfigParser.h Intersection.cpp Intersection.h Lane.h Lane.cpp randomGen.cpp randomGen.h Section.cpp Section.h TrafficLight.cpp TrafficLight.h VehicleBase.cpp VehicleBase.h
	$(CC) $(CCFLAGS) Simulation.cpp

testAnimator: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
