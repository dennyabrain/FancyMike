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
float inByte;
float param;

void setup(){
  size(400,200);
  minim = new Minim(this);
  out = minim.getLineOut();
  myDelay = new Delay(0.5,0.8,true,true);
  //myDelay = new Delay(0.001);
  bitCrush = new BitCrush(16,out.sampleRate());
  
  AudioStream inputStream = minim.getInputStream(out.getFormat().getChannels(),
                                                 out.bufferSize(),
                                                 out.sampleRate(),
                                                 out.getFormat().getSampleSizeInBits());                                                 
 in = new LiveInput(inputStream);
 //in.patch(myDelay).patch(bitCrush).patch(out);
 in.patch(myDelay).patch(out);
 //in.patch(out);
 //println(Serial.list());
 myPort = new Serial(this, "/dev/ttyACM0",9600);
}

void draw(){
  background(#FFFFFF);
  text(delayTime,80,60);
  
}

void mouseMoved()
{
  // set the delay time by the horizontal location
 // delayTime = map( mouseY, 0, height, 0.0001, 1 );
 // myDelay.setDelTime( delayTime );
  float bits = map( mouseX, 0, width, 1, 16 );
  bitCrush.setBitRes(bits);
}

void serialEvent(Serial myPort){
  inByte= myPort.read();
  //println(inByte);
  param=map(inByte,150,250,0.001,0.5);
  println(param);
  
  /*
  switch(char(inByte)){
    case '0': //slowest
      //param=0.5;
      param=0.001;
      println(param);
      break;
    case '1':
      //param=0.3;
      param=0.005;
      println(param);
      break;
    case '2':
      //param=0.2;
      param=0.05;
      println(param);
      break;
    case '3':
      //param=0.05;
      param=0.2;
      println(param);
      break;
    case '4':
      //param=0.005;
      param=0.3;
      println(param);
      break;
    case '5': //fastes
      //param=0.001;
      //param=0.5;
      param=0;
      println(param);
      break;
    default:
      //println("default");
      break;
  }*/
 myDelay.setDelTime(param);
}
