#version 330 core
in vec3 color_1;
in vec2 tex_coord;

out vec4 color;

uniform sampler2D texture_1;

void main()
{
	color = texture(texture_1, tex_coord);
}