#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

out vec2 v_texCoord;

void main()
{
	v_texCoord = texCoord;
	gl_Position = u_proj * u_view * u_model * position;
};

#shader fragment
#version 330 core

uniform sampler2D u_texture;
uniform vec3 u_colorMultiplier = vec3(1.0f, 1.0f, 1.0f);

in vec2 v_texCoord;
out vec4 color;

void main()
{
	color = vec4(u_colorMultiplier * vec3(texture(u_texture, v_texCoord)), 1.0f);
};