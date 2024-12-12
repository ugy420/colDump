import cv2
import matplotlib.pyplot as plt
import numpy as np

Lenna = cv2.imread("Lenna.jpg")

GsLenna = cv2.cvtColor(Lenna, cv2.COLOR_BGR2GRAY)

max_val = GsLenna.max()
min_val = GsLenna.min()

GsLenna_linear = np.empty_like(GsLenna, dtype=np.uint8)

for i in range(GsLenna.shape[0]):
    for j in range(GsLenna.shape[1]):
        pixel = GsLenna[i, j]
        normalized_pixel = ((pixel - min_val) * 255 / (max_val - min_val))
        GsLenna_linear[i, j] = np.uint8(normalized_pixel)

GsLenna_dotfive = (((GsLenna/255) ** (1/0.5)) * 255).astype(np.uint8)
GsLenna_onefive = (((GsLenna/255) ** (1/1.5)) * 255).astype(np.uint8)
GsLenna_twotwo = (((GsLenna/255) ** (1/2.2)) * 255).astype(np.uint8)
# np.uint8 can be used instead of looping for individual pixel value.

cv2.imwrite("GsLenna.jpg", GsLenna)
cv2.imwrite("GsLenna Linear.jpg",GsLenna_linear)
cv2.imwrite("GsLenna 0.5.jpg",GsLenna_dotfive)
cv2.imwrite("GsLenna 1.5.jpg",GsLenna_onefive)
cv2.imwrite("GsLenna 2.2.jpg",GsLenna_twotwo)
cv2.waitKey(0)

hist = cv2.calcHist([GsLenna], [0], None, [256], [0, 256])
hist_normalized = cv2.calcHist([GsLenna_linear], [0], None, [256], [0, 256])
hist_gammadotfive = cv2.calcHist([GsLenna_dotfive], [0], None, [256], [0, 256])
hist_gammaonefive = cv2.calcHist([GsLenna_onefive], [0], None, [256], [0, 256])
hist_gammatwotwo = cv2.calcHist([GsLenna_twotwo], [0], None, [256], [0, 256])

plt.plot(hist)
plt.title('Original Grayscale Histogram')
plt.xlabel('Pixel intensity')
plt.ylabel('Frequency')
plt.show()

plt.plot(hist_normalized)
plt.title('Normalized Grayscale Histogram')
plt.xlabel('Pixel intensity')
plt.ylabel('Frequency')
plt.show()

plt.plot(hist_gammadotfive)
plt.title('Gamma 0.5 Histogram')
plt.xlabel('Pixel intensity')
plt.ylabel('Frequency')
plt.show()

plt.plot(hist_gammaonefive)
plt.title('Gamma 1.5 Histogram')
plt.xlabel('Pixel intensity')
plt.ylabel('Frequency')
plt.show()

plt.plot(hist_gammatwotwo)
plt.title('Gamma 2.2 Histogram')
plt.xlabel('Pixel intensity')
plt.ylabel('Frequency')
plt.show()
