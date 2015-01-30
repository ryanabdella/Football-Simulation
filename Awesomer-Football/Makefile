OPTS = -Wall -g
LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

football: football.o texture.o gamesim.o ColorPoint2.h
	g++ -I /usr/local/boost_1_48_0 $(OPTS) -o football football.o texture.o gamesim.o $(LIBS)

football.o: football.cpp button.h team.h player.h accum.h defstat.h gamesim.h gamesim.cpp
	g++ -I /usr/local/boost_1_48_0 $(OPTS) -c football.cpp

texture.o: texture.cpp texture.h
	g++ -I /usr/local/boost_1_48_0 $(OPTS) -c texture.cpp

gamesim.o: gamesim.cpp gamesim.h team.h player.h defstat.h accum.h
	g++ -I /usr/local/boost_1_48_0 $(OPTS) -c gamesim.cpp

clean:
	rm -f *.o football