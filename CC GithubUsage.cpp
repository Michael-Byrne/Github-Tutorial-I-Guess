// CC GithubUsage.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
using namespace tle;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\Program Files (x86)\\TL-Engine\\Media" );

	/**** Set up your scene here ****/

	//Camera
	ICamera* myCam = myEngine->CreateCamera(kFPS);

	//Floor
	IMesh* floorMesh = myEngine->LoadMesh("Cube.x");
	IModel* floor = floorMesh->CreateModel(0, 0, 0);


	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();

		/**** Update your scene each frame here ****/

		if (myEngine->KeyHit(Key_Escape))
		{
			myEngine->Stop();
		}

	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}
