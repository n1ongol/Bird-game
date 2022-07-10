app: main.cpp bird.cpp bird.h SETTINGS.h Triangles.h Triangles.cpp
	g++ *.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system
