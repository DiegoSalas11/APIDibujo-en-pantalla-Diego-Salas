#include "ofApp.h"
#include "ofMath.h"

void ofApp::setPoint(int x, int y)
{
	posx = x;
	posy = y;
}

void ofApp::moveTo(int x, int y)
{
	line(posx, posy, x, y, color.r, color.g, color.b);
	setPoint(x, y);
}

void ofApp::setColor(ofColor color)
{
	this->color.set(color);
}

ofColor ofApp::getColor()
{
	return color;
}
//--------------------------------------------------------------
void ofApp::setup(){
	pixeles.allocate(1024, 768, OF_PIXELS_RGB);
	textura.allocate(1024, 768, GL_RGB);
	posx = 0;
	posy = ofGetHeight()/2;
	setPoint(ofRandom(1, 1023), ofRandom(1, 768));
	/*godx = ofRandom(1,1023);
	gody = ofRandom(1,768);*/
	//arriba 300 aajo
}

//--------------------------------------------------------------
void ofApp::update(){
	getPixel();
	
	moveTo(ofRandom(1, 1023), ofRandom(1, 768));

	/*godx = ofRandom(1,ofGetWidth()-1);
	gody = ofRandom(1,ofGetHeight()-1);

	line(posx, posy,godx ,gody , 255, 0, 0);*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	textura.draw(0, 0);
}
void ofApp::putPixel(int x, int y, int red, int green, int blue)
{
	ofColor color;
	color.set(red, green,blue);
	pixeles.setColor(x, y, color);
}

int ofApp::line(int x1, int y1, int x2, int y2, int r, int g, int b)
{
	

	if (x1 > x2)// invierte
	{
		int xNew = x1;
		int yNew = y1;

		x1 = x2;
		y1 = y2;

		x2 = xNew;
		y2 = yNew;

		
		
	}

	if (y1 > y2)// diferencia negativa?
	{
		unoOmenosUno = -1;
		dy = y1 - y2;
	}
	else
	{
		dy = y2 - y1;
		unoOmenosUno = 1;
	}
	dx = x2 - x1;
	if (dy >= dx)//  Base mayor 
	{
		a = dx;
		b = -dy;
		Subebaja = x1;
		filtroDeAlberca = true;
	}
	else
	{
		a = dy;
		b = -dx;
		Subebaja = y1;
		filtroDeAlberca = false;
	}

	d = 2 * a + b;
	difE = 2 * a;
	difNE = 2 * a + 2 * b;
	putPixel(x1, y1, r, g, b);
	if (!filtroDeAlberca)
	{
		for (int x = x1 + 1; x <= x2; x++)
		{
			if (d < 0)
			{
				d += 2 * a;
			}
			else
			{
				d += 2 * a + 2 * b;
				Subebaja += unoOmenosUno;
			}
			putPixel(x, Subebaja, r, g, b);
		}
	}
	else
	{
		cout << "el agua esa limpia" << endl;
		int elintquesepasodeverga;
		int otra = y2 *= unoOmenosUno;
		for (int y = y1 + unoOmenosUno; (elintquesepasodeverga = y*unoOmenosUno) <= (otra); y += unoOmenosUno)
		{
			if (d < 0)
			{
				d += 2 * a;
			}
			else
			{
				d += 2 * a + 2 * b;
				Subebaja++;
			}
			putPixel(Subebaja, y, r, g, b);
		}



	}
	return 0;
	
}



void ofApp::getPixel()
{
	textura.loadData(pixeles);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}


//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
