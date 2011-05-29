#include <vector>
using namespace std;

#include "Structures.hpp"
#include "Ray.hpp"
#include "Light.hpp"

void createImage(Scene scene, int screenWidth, int screenHeight){

	int i,j,k;
	int level, currentSphere;
	
	Colour cor;
	Ray raio;
	
	double reflection = 0.0f;
	
	for(i=0;i < screenWidth; i++){
		for(j=0; j < screenHeight; j++){
			
			cor = 0.0f;
			raio.start.x = double(i);
			raio.start.y = double(j);
			raio.start.y = -1000.0f;
			
			raio.direction.x = 0.0f;
			raio.direction.y = 0.0f;
			raio.direction.z = 1.0f;
			
			level = 0;
			
			while (level < 10 && reflection > 0.0f){
					
				Point hitPoint;
				currentSphere = -1;
				
				double t = 2000.0f;
				/*for(k=0; k < scene.spheres.size(); k++){

				}*/
				
			}
		}
	
	}

}


