import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

Minim minim;
LiveInput in;
AudioOutput out;

void setup(){
  size(800,800);
  minim = new Minim(this);
  out = minim.getLineOut();
  
  AudioStream inputStream = minim.getInputStream(out.getFormat().getChannels(),
                                                 out.bufferSize(),
                                                 out.sampleRate(),
                                                 out.getFormat().getSampleSizeInBits());
                                                 
 in = new LiveInput(inputStream);

 in.patch(out);
}

void draw(){
}
