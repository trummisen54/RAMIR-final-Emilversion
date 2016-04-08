#include "Display.hpp"



//===============CONSTRUCTOR  DESTRUCTOR=====================

Display::Display()
{
	windowNamesVector = new vector<char *>();
}


Display::~Display()
{
	destroyAllWindows();
	delete windowNamesVector;
}


//===========================================================





void Display::resizeImage(Mat * img)
{
	double multiplier = 1.0;

	int width = img->cols * multiplier;
	int height = img->rows * multiplier;

	Size size(width, height);
	resize(*img, *img, size);
}



void Display::showImage(Mat * img, int windowIndex)
{
	moveWindow(windowNamesVector->at(windowIndex), (5+img->cols)*(windowIndex%2), (40+img->rows)*(windowIndex/2)); //Position windows in a gridlayout
	imshow(windowNamesVector->at(windowIndex), *img);
}






void Display::createWindow(char *str)
{
	if (str != "Settings") //Exclude window named "Settings" from the positioning algorithm
	{
		namedWindow(str, WINDOW_AUTOSIZE);
		windowNamesVector->push_back(str);
	} 
	else
	{
		namedWindow(str, WINDOW_NORMAL);
	}
}



//================================================================




