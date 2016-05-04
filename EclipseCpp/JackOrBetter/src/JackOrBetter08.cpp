#include "Application.h"


int main(int argc, char* args[])
{
	Application app;

	    if(app.Init())
	    {
	        app.MainLoop();
	    }

	    return 0;
}
