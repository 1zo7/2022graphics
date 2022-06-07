//drag all files into the sketch
PShape gundam;
void setup(){
  size(500,500,P3D);
  gundam = loadShape("Gundam.obj");
}
void draw(){
  background(128);
  translate(250,400, 0);
  scale(10,-10,10);//x,y,z
  rotateY(radians(frameCount));
  shape(gundam);
}
