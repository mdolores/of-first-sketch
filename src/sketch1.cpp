#include "sketch1.h"

int MINX = 100;
int MINY = 100;
int WIDTH = 620;
int HEIGHT = 580;
int MIN_RADIUS = 10;
int MAX_RADIUS = 100;
int DELTA = 10;
int RECT_RADIUS = 15;
int circleX, circleY;
int radius;
bool dirX, dirY, dirRadius, changeDir;
int maxX, maxY;
int r,g,b;

void sketch1::setup(){
    dirX = true;
    dirY = true;
    changeDir = false;
    maxX = MINX + WIDTH;
    maxY = MINY + HEIGHT;
    dirRadius = true;
    radius = MIN_RADIUS;
    circleX = MINX + radius;
    circleY = MINY + radius;
    ofSetFrameRate(60);
    r = g = b = 0;
}

void sketch1::update(){
    changeDir = false;
    if (circleX >= maxX - radius) {
        dirX = false;
        changeDir = true;
    }
    else if (circleX <= MINX + radius) {
        dirX = true;
        changeDir = true;
    }
    if (circleY >= maxY - radius) {
        dirY = false;
        changeDir = true;
    }
    else if (circleY <= MINY + radius) {
        dirY = true;
        changeDir = true;
    }
    circleX += (dirX ? DELTA : -DELTA);
    circleY += (dirY ? DELTA : -DELTA);
    if (radius >= MAX_RADIUS) {
        dirRadius = false;
    }
    else if (radius <= MIN_RADIUS) {
        dirRadius = true;
    }
    radius += (dirRadius ? 1 : -1);
    if (changeDir) {
        r = ofRandom(255);
        g = ofRandom(255);
        b = ofRandom(255);
    }
}

void sketch1::draw(){
    ofSetColor(0,0,0);
    ofDrawBitmapString("Rate " + ofToString(ofGetFrameRate()) + "fps", 10, 15);
    ofDrawBitmapString("circleX " + ofToString(circleX) + " circleY " + ofToString(circleY), 10, 30);
    ofDrawBitmapString("X bound " + ofToString(maxX - radius) + " Y bound " + ofToString(maxY - radius), 10, 45);
    ofDrawBitmapString(" radius " + ofToString(radius), 10, 60);
    ofDrawRectRounded(MINX,
                      MINY,
                      WIDTH,
                      HEIGHT,
                      RECT_RADIUS);
    ofSetColor(r, g, b);
    ofDrawCircle(circleX, circleY, radius);
}
