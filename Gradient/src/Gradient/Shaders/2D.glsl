#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;

void main()
{
	v_texCoord = texCoord;
	gl_Position = position;
};

#shader fragment
#version 330 core

uniform sampler2D tex;

in vec2 v_texCoord;
out vec4 color;

void main()
{
	color = texture(tex, v_texCoord);
};