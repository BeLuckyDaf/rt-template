#include "denoising.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <time.h>
#include <omp.h>
#include <random>

Denoising::Denoising(short width, short height) : AABB(width, height)
{
	raytracing_depth = 16;
}

Denoising::~Denoising()
{
}

void Denoising::Clear()
{
	history_buffer.resize(width * height);
	frame_buffer.resize(width * height);
}

Payload Denoising::Hit(const Ray& ray, const IntersectableData& data, const MaterialTriangle* triangle, const unsigned int max_raytrace_depth) const
{
}

void Denoising::SetHistory(unsigned short x, unsigned short y, float3 color)
{
	history_buffer[y * width + x] = color;
}

float3 Denoising::GetHistory(unsigned short x, unsigned short y) const
{
	return history_buffer[y * width + x];
}


Payload Denoising::Miss(const Ray& ray) const
{
}

int Denoising::GetRandom(const int thread_num) const
{
}

void Denoising::DrawScene(int max_frame_number)
{
}

void Denoising::LoadBlueNoise(std::string file_name)
{
	int width, height, channels;
	unsigned char* img = stbi_load(file_name.c_str(), &width, &height, &channels, 0);
	for (int i = 0; i < width * height; i++) 
	{
		float3 pixel{(img[channels * i]-128.f)}
	}
}
