/*
   The GLSmartTexMag filter shader
   
   Based on a shader Copyright (C) 2009 guest(r) - guest.r@gmail.com - that was found at
   http://www.razyboard.com/system/morethread-smart-texture-mag-filter-for-ogl2-and-dosbox-pete_bernert-266904-5689051-0.html
   
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

uniform sampler2D Texture;
uniform sampler2D lightTexture;
uniform bool useLightTexture;

void main()
{
	vec2 fw = fwidth(gl_TexCoord[0].xy);
	float x = fw.x;
	float y = fw.y;

	vec2 sd1 = vec2( x,y) * 0.5;
	vec2 sd2 = vec2(-x,y) * 0.5;

	vec2 ddx = vec2(  x, 0.0);
	vec2 ddy = vec2(0.0,   y);

	vec4 c11 = texture2D(Texture, gl_TexCoord[0].xy);
	vec4 s00 = texture2D(Texture, gl_TexCoord[0].xy-sd1);
	vec4 s20 = texture2D(Texture, gl_TexCoord[0].xy-sd2);
	vec4 s22 = texture2D(Texture, gl_TexCoord[0].xy+sd1);
	vec4 s02 = texture2D(Texture, gl_TexCoord[0].xy+sd2);   
	vec4 c01 = texture2D(Texture, gl_TexCoord[0].xy-ddy);
	vec4 c21 = texture2D(Texture, gl_TexCoord[0].xy+ddx);
	vec4 c10 = texture2D(Texture, gl_TexCoord[0].xy+ddy);
	vec4 c12 = texture2D(Texture, gl_TexCoord[0].xy-ddx);
	vec4 dt = vec4(1.0,1.0,1.0,1.0);
		
	float hl=dot(abs(c01-c21),dt)+0.0001;
	float vl=dot(abs(c10-c12),dt)+0.0001;
	float m1=dot(abs(s00-s22),dt)+0.0001;
	float m2=dot(abs(s02-s20),dt)+0.0001;

	vec4 temp1 = m2*(s00 + s22) + m1*(s02 + s20);
	vec4 temp2 = hl*(c10 + c12) + vl*(c01 + c21);

	gl_FragColor = (temp2/(hl+vl) + c11 + c11) * 0.083333 + (temp1/(m1+m2)) * 0.333333;
	
	vec3 col;
	if (useLightTexture) {
		vec4 texture1 = texture2D (lightTexture, gl_TexCoord[1].xy);
		col = texture1.rgb * gl_FragColor.rgb;
	} else {
		col = gl_Color.rgb * gl_FragColor.rgb;
	}
	col += vec3(gl_SecondaryColor);
	gl_FragColor = vec4 (col, gl_Color.a * gl_FragColor.a);
}
