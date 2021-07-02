#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;
layout(location = 2) in vec2 texCoords;
layout(location = 3) in vec4 tangent;

out vec3 v_normal;
out vec2 v_texCoords;
out vec3 v_fragPos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
	// send data to fragment shader
	v_normal = vec3(u_model * normal);
	v_texCoords = texCoords;
	v_fragPos = vec3(u_model * position);

	// compute transformation
	gl_Position = u_proj * u_view * u_model * position;
};

#shader fragment
#version 330 core
#define MAX_POINTLIGHTS 128
#define MAX_DIRLIGHTS 4

struct MaterialTexture
{
	sampler2D Diffuse;
	sampler2D Specular;

	float Shininess;
};

struct PointLight
{
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	vec3 Position;
};

struct DirectionalLight
{
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	vec3 Direction;
};

out vec4 color;

in vec3 v_normal;
in vec2 v_texCoords;
in vec3 v_fragPos;

uniform MaterialTexture u_mat;
uniform vec3 u_viewPos;
uniform int u_pointLightsSize;
uniform PointLight u_pointLights[MAX_POINTLIGHTS];
//uniform int u_dirLightsSize; // DC
//uniform DirectionalLight u_dirLights[MAX_DIRLIGHTS]; // DC

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.Position - fragPos);
	// diffuse shading
	float diff = max(dot(normal, lightDir), 0.0f);
	// specular shading
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), u_mat.Shininess);
	// attenuation
	float distance = length(light.Position - fragPos);
	//float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	// combine results
	vec3 ambient = light.Ambient * vec3(texture(u_mat.Diffuse, v_texCoords));
	vec3 diffuse = light.Diffuse * diff * vec3(texture(u_mat.Diffuse, v_texCoords));
	vec3 specular = light.Specular * spec * vec3(texture(u_mat.Specular, v_texCoords));
	//ambient *= attenuation;
	//diffuse *= attenuation;
	//specular *= attenuation;
	return (ambient + diffuse + specular);
}

void main()
{
	vec3 norm = normalize(v_normal);
	vec3 viewDir = normalize(u_viewPos - v_fragPos);

	vec3 result = vec3(0.0f);
	
	// TODO: dirlight

	for (int i = 0; i < u_pointLightsSize; i++)
		result += CalcPointLight(u_pointLights[i], norm, v_fragPos, viewDir);

	color = vec4(result, 1.0f);
};