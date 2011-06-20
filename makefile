all:
	g++ rayTracer.cpp main.cpp Object.cpp Sphere.cpp Ray.cpp Light.cpp Cylinder.cpp Wall.cpp Cone.cpp -o tracer.exe -lopengl32 -lglut32 -lglu32 -g