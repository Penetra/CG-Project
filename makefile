all:
	g++ rayTracer.cpp main.cpp Object.cpp Sphere.cpp Ray.cpp Light.cpp Wall.cpp -o tracer.exe -lopengl32 -lglut32 -lglu32 -g