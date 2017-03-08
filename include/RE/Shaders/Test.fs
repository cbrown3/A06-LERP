#version 330

in vec3 Color;

out vec4 Fragment;
in vec2 UV;

uniform sampler2D TextureID;

void main()
{
		
	Fragment = texture( TextureID, UV );
	

	return;
}