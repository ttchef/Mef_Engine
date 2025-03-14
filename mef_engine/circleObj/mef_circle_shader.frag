
#version 430 core

vec2 iResolution = vec2(800, 600);

uniform float uTime;

out vec4 fragColor;

// Operators
float smin(float a, float b, float k)
{
    float h = max(k-abs(a-b),0.0)/k;
    return min(a,b)-h*h*h*k*(1.0/6.0);
}

float sdSphere(vec3 p, float s)
{
    return length(p) - s;
}

float sdBox(vec3 p, vec3 b)
{
    vec3 q = abs(p) - b;
    return length(max(q,0.0)) + min(max(q.x,max(q.y,q.z)),0.0);
}

float map(vec3 p)
{
    float time = uTime;
    vec3 spherePos = vec3(sin(time)*3.0,0,0);
    float sphere = sdSphere(p - spherePos, 1.0);
    
    float box = sdBox(p, vec3(0.75)); // CUBE SDF
    
    float ground = p.y + 0.75;

    return smin(ground, smin(sphere, box, 2.0), 1.0);
}   

void main(void)
{
    vec2 uv = (gl_FragCoord.xy * 2.0 - iResolution.xy) / iResolution.y;
    
    vec3 ro = vec3(0, 0, -3); // ray origin
    vec3 rd = normalize(vec3(uv, 1)); // ray direction
    vec3 col = vec3(0);

    float t = 0.; // total distance travelled

    // Raymarching
    for (int i = 0; i < 80; i++)
    {
        vec3 p = ro + rd * t; // position along the ray
        float d = map(p); // current distance to the scene
        t += d;

        // Optimization
        if (d < 0.001 || t > 100.0) break;
    }

    // Coloring
    col = vec3(t * 0.2); // color based on distance

    fragColor = vec4(col, 1);
}


