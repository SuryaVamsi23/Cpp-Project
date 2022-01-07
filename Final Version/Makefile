#OBJS specifies which files to compile as part of the project
OBJS = Component.o AngleBar.o AngleBar2.o Button.o startButton.o Table.o StationaryPaperBall.o Dustbin.o ComponentManager.o  Dustbin2.o ExitButton.o Game_Background.o Level2.o MainBackground.o Mouse.o MovingPaperBall.o MovingPaperBall2.o PowerBar.o PowerBar2.o Winner.o Main.o

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lm

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = project

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm *.o project