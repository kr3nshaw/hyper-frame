#version 150 core

in vec3 Pos;
in vec2 tex;

out vec2 Tex;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
	gl_Position = Projection * View * Model * vec4(Pos, 1.0);
	Tex = tex;
}
