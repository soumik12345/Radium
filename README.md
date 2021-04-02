# Radium

Radium is a simple bare-bones Ray Tracing Engine written in C++ that runs on the CPU on a single thread. Frames rendered by Radium are saved in PPM format.

## Features

- Simple and easy-to-use API.

- Global illumination using Unbiased Monte Carlo Path Tracing.

- Soft shadows from Diffuse Light Sources.

- Specular, Diffuse, and Refractive Materials are supported.

- Total Internal Reflection for Refractive Materials.

- Russian Roulette for path termination.

**Note:** Radium has been tested on MacOS and Linux. Support for Windows is Experimental.

## Instructions

- `git clone --recursive https://github.com/soumik12345/Radium`

- Make sure you have CMake installed for your system.

- `sh ./build_and_run.sh`

- In order to run Radium on Google Colab, refer to [![](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/soumik12345/Radium/blob/monte_carlo/notebooks/Demo.ipynb).

## Demos

### Simple Cornell Box with a Specular and Refractive Sphere (Rendered at 1000 Samples per Pixel)

![](./assets/simple_cornell_box.png)
