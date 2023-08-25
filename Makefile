TARGET=learning_sfml
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX=clang++
OBJS=src/main.cpp src/player.cpp 

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -rf *.o

