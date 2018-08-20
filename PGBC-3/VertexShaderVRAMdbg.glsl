#version 430

in layout(location=0) vec2 position;
in layout(location=1) vec3 vertexColor;

out vec3 theColor;

uniform float size;
uniform float width;
uniform float height;

void main()
{
	gl_PointSize = size;

	float posXort = (2.0 * position.x - width) / width;
	float posYort = (height - 2.0 * position.y) / height;

	gl_Position = vec4(posXort, posYort, 0.0, 1.0);
	theColor = vertexColor;
}