#version 330

in vec3 Position_W;
in vec2 UV;

uniform sampler2D TextureID;
uniform vec3 Color;

out vec4 Fragment;

void main()
{
	Fragment = texture( TextureID, UV );
	Fragment = Fragment * vec4(Color,1);

	return;
}