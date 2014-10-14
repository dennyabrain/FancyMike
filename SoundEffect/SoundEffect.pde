import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

import processing.serial.*;

Minim minim;
LiveInput in;
AudioOutput out;
Delay myDelay;
BitCrush bitCrush;
float delayTime;

Serial myPort;
int inByte;
float param;

void setup(){
  size(800,800);
  minim = new Minim(this);
  out = minim.getLineOut();
  myDelay = new Delay(0.6,0.8,true,true);
  bitCrush = new BitCrush(16,out.sampleRate());
  
  AudioStream inputStream = minim.getInputStream(out.getFormat().getChannels(),
                                                 out.bufferSize(),
                                                 out.sampleRate(),
                                                 out.getFormat().getSampleSizeInBits());                                                 
 in = new LiveInput(inputStream);
 //in.patch(myDelay).patch(bitCrush).patch(out);
 in.patch(myDelay).patch(out);
 println(Serial.list());
 myPort = new Serial(this, "portname",9600);
}

void draw(){
  background(#FFFF80);
  text(delayTime,80,60);
  
}

void mouseMoved()
{
  // set the delay time by the horizontal location
  //delayTime = map( mouseY, 0, height, 0.0001, 1 );
  //myDelay.setDelTime( delayTime );
 // float bits = map( mouseX, 0, width, 1, 16 );
 // bitCrush.setBitRes(bits);
}

void serialEvent(Serial myPort){
  inByte= myPort.read();
  println(inByte);
  switch(inByte){
    case 0:
      param=0.5;
      break;
    case 1:
      param=0.3;
      break;
    case 2:
      param=0.2;
      break;
    case 3:
      param=0.05;
      break;
    case 4:
      param=0.005;
      break;
    case 5:
      param=0.001;
      break;
    default:
      break;
  }
  myDelay.setDelTime(param);
}
