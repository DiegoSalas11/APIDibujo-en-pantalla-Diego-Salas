#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofColor color;
		void setPoint(int x , int y);
		void moveTo(int x, int y);
		void setColor(ofColor color);
		ofColor getColor();

		int godx, gody;
		int posx, posy;

		void setup();
		void update();
		void draw();
		ofTexture textura;
		ofPixels pixeles;
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void putPixel(int x, int y, int red, int green, int blue);
		int line(int x1, int y1, int x2, int y2, int r, int g, int b);

		void getPixel();
		int dx, dy, a, b, d, difE, difNE, Subebaja, unoOmenosUno;
		bool filtroDeAlberca;
		
};
