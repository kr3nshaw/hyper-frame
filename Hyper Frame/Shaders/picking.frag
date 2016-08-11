#version 150 core

out vec4 Colour;

uniform int Code;

void main()
{
	Colour = vec4(Code / 255.0);
}
