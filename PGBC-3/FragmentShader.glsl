#version 430

out vec4 daColor;
in vec3 theColor;

void main()
{
	daColor = vec4(theColor.x/255.0, theColor.y/255.0, theColor.z/255.0, 1.0);
}
