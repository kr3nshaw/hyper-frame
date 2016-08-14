#version 150 core

in vec3 in_position;
in vec2 in_texture;

out vec2 Texture;

uniform mat4 in_model;
uniform mat4 in_view;
uniform mat4 in_projection;

void main()
{
	gl_Position = in_projection * in_view * in_model * vec4(in_position, 1.0);
	Texture = in_texture;
}
