import numpy as np
import matplotlib.pyplot as plt

def mandelbrot(c, max_iter):
	z = 0
	n = 0
	while abs(z) <= 2 and n < max_iter:
		z = z**2 + c
		n += 1
	return n

def mandelbrot_set(width, height, x_min, x_max, y_min, y_max, max_iter):
	image = np.zeros((width, height))

	for x in range(width):
		for y in range(height):
			real = x * (x_max - x_min) / (width - 1) + x_min
			imag = y * (y_max - y_min) / (height - 1) + y_min
			c = complex(real, imag)
			image[x, y] = mandelbrot(c, max_iter)

	return image

if __name__ == "__main__":
	width, height = 800, 800
	x_min, x_max = -2, 2
	y_min, y_max = -2, 2
	max_iter = 1000

	mandelbrot_image = mandelbrot_set(width, height, x_min, x_max, y_min, y_max, max_iter)

	plt.imshow(mandelbrot_image, cmap='viridis', extent=(x_min, x_max, y_min, y_max))
	plt.colorbar()
	plt.title("Mandelbrot Set")
	plt.show()
