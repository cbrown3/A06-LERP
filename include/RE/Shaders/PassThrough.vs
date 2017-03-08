#version 330
layout (location = 0) in vec3 Position_b;
layout (location = 2) in vec3 UV_b;

out vec2 UV;

void main()
{
	gl_Position = vec4(Position_b, 1);
	UV = UV_b.xy;
}