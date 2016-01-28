clear all;
clc;
close all;

g=0.8;
d = 4;


w = -pi: 2*pi/1000 : pi - 2*pi/1000;
H = (1+g.^2)+2*g*cos(w*d);

plot(w,sqrt(H));