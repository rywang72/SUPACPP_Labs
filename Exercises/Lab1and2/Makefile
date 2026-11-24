# Macros
CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags
TARGET=AnalyseData #Executable name
OBJECTS=AnalyseData.o CostomFunctions.o

# Link
${TARGET}:${OBJECTS}
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}

# Compile
CostomFunctions.o:CostomFunctions.cpp CostomFunctions.h
	${CC} ${FLAGS} -c CostomFunctions.cpp

AnalyseData.o:AnalyseData.cpp CostomFunctions.h
	${CC} ${FLAGS} -c AnalyseData.cpp