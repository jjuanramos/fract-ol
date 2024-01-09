import numpy as np
import matplotlib.pyplot as plt

def julia(c, z, max_iter):
	n = 0
	while abs(z) <= 2 and n < max_iter:
		z = z**2 + c
		n += 1
	return n

def julia_set(width, height, x_min, x_max, y_min, y_max, c, max_iter):
	image = np.zeros((width, height))

	for x in range(width):
		for y in range(height):
			real = x * (x_max - x_min) / (width - 1) + x_min
			imag = y * (y_max - y_min) / (height - 1) + y_min
			z = complex(real, imag)
			image[x, y] = julia(c, z, max_iter)

	return image

if __name__ == "__main__":
	width, height = 800, 800
	x_min, x_max = -2, 2
	y_min, y_max = -2, 2
	c = complex(-0.7, 0.27015)  # Adjust the constant 'c' for the Julia set
	max_iter = 100

	julia_image = julia_set(width, height, x_min, x_max, y_min, y_max, c, max_iter)

	plt.imshow(julia_image, cmap='viridis', extent=(x_min, x_max, y_min, y_max))
	plt.colorbar()
	plt.title("Julia Set")
	plt.show()