#ifndef RADIUM_UTIL_DOTPRODUCT_H
#define RADIUM_UTIL_DOTPRODUCT_H

#include <cuda_runtime.h>
#include <math.h>

typedef unsigned int uint;
typedef unsigned short ushort;


inline __host__ __device__ float dotProduct(float2 a, float2 b) { return a.x * b.x + a.y * b.y; }

inline __host__ __device__ float dotProduct(float3 a, float3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

inline __host__ __device__ float dotProduct(float4 a, float4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

inline __host__ __device__ int dotProduct(int2 a, int2 b) { return a.x * b.x + a.y * b.y; }

inline __host__ __device__ int dotProduct(int3 a, int3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

inline __host__ __device__ int dotProduct(int4 a, int4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

inline __host__ __device__ uint dotProduct(uint2 a, uint2 b) { return a.x * b.x + a.y * b.y; }

inline __host__ __device__ uint dotProduct(uint3 a, uint3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

inline __host__ __device__ uint dotProduct(uint4 a, uint4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
