#version 150 core

in vec3 in_position;

uniform mat4 in_model;
uniform mat4 in_view;
uniform mat4 in_projection;

void main()
{
	gl_Position = in_projection * in_view * in_model * vec4(in_position, 1.0);
}
