#version 150 core

in vec2 Tex;

out vec4 Colour;

uniform sampler2D Sampler2D;

void main()
{
	Colour = texture(Sampler2D, Tex);
}
