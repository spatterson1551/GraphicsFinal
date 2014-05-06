#version 130

in vec3 fs_light;
in vec3 fs_normal;
in vec3 fs_position;
in vec3 fs_color;
in vec3 camPosition;

out vec4 out_Color;

void main() {
	int specPower = 32;

	out_Color = vec4(fs_color.x, fs_color.y, fs_color.z, 1.0)/5;

	//float diff = max(0.0, dot(fs_normal, fs_light));
	float diff = clamp(-dot(fs_light, fs_normal), 0, 1);
	out_Color += diff*vec4(fs_color.x, fs_color.y, fs_color.z, 0.0);
	
	
	vec3 V = normalize(camPosition - fs_position);
	vec3 H = normalize(fs_light + V);

	float spec = pow(max(0.0, dot(H, fs_normal)), specPower);
	//out_Color += spec*fs_color;
	//out_Color += spec*vec4(fs_color.x, fs_color.y, fs_color.z, 0.0)*100;
	out_Color += spec*vec4(1, 1, 1, 1)*100;

	if(out_Color.x > 1.0)
		out_Color.x = 1.0;
	if(out_Color.y > 1.0)
		out_Color.y = 1.0;
	if(out_Color.z > 1.0)
		out_Color.z = 1.0;
	if(out_Color.w > 1.0)
		out_Color.w = 1.0;
}