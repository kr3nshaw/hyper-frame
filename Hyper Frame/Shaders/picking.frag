#version 150 core

out vec4 Colour;

uniform int in_code;

void main()
{
	Colour = vec4(in_code / 255.0);
}
