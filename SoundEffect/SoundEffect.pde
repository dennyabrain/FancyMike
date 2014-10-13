import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

Minim minim;
LiveInput in;
AudioOutput out;
//Delay myDelay;
BitCrush bitCrush;

void setup(){
  size(800,800);
  minim = new Minim(this);
  out = minim.getLineOut();
  //myDelay = new Delay(0.6);
  bitCrush = new BitCrush(16,out.sampleRate());
  
  AudioStream inputStream = minim.getInputStream(out.getFormat().getChannels(),
                                                 out.bufferSize(),
                                                 out.sampleRate(),
                                                 out.getFormat().getSampleSizeInBits());
                                                 
 in = new LiveInput(inputStream);

 in.patch(bitCrush).patch(out);
}

void draw(){
  
}

void mouseMoved()
{
  // set the delay time by the horizontal location
  //float delayTime = map( mouseX, 0, width, 0.0001, 0.5 );
  //myDelay.setDelTime( delayTime );
  float bits = map( mouseX, 0, width, 1, 16 );
  bitCrush.setBitRes(bits);
}
