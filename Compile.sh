#!/bin/bash

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o BrainMemory.o ./Srcs/BrainMemory.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o Game.o ./Srcs/Game.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o Layer.o ./Srcs/Layer.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o main.o ./Srcs/main.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o MainWindow.o ./Srcs/MainWindow.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o NeuralNetwork.o ./Srcs/NeuralNetwork.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o RandomMachine.o ./Srcs/RandomMachine.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o SnakeBrain.o ./Srcs/SnakeBrain.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o SnakeSquad.o ./Srcs/SnakeSquad.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o SnakeView.o ./Srcs/SnakeView.cpp

g++ -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I./Includes -I./Libs/Qt/includes -I./Libs/Qt/includes/QtWidgets -I./Libs/Qt/includes/QtGui -I./Libs/Qt/includes/QtCore -I./Libs/SFML/includes -I./Libs/SFML/includes/SFML -I. -isystem /usr/include/libdrm -I. -I/opt/Qt/5.9.1/gcc_64/mkspecs/linux-g++ -o moc_MainWindow.o ./Srcs/moc_MainWindow.cpp

g++ -Wl,-O1 -Wl,-rpath,./Libs/SFML/bin -Wl,-rpath,./Libs/Qt/bin -o Snake main.o MainWindow.o BrainMemory.o Game.o Layer.o NeuralNetwork.o RandomMachine.o SnakeBrain.o SnakeSquad.o SnakeView.o moc_MainWindow.o -L./Libs/SFML/bin -lsfml-graphics -lsfml-system -lsfml-window -L./Libs/Qt/bin -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread

rm BrainMemory.o Game.o Layer.o main.o MainWindow.o NeuralNetwork.o RandomMachine.o SnakeBrain.o SnakeSquad.o SnakeView.o moc_MainWindow.o
