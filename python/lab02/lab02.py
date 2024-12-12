import cv2
image = cv2.imread('colorimg.jpg')
grayscaleImage = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

height, width, _ = image.shape

top_left_x = 100
top_left_y = 100
side_length = 200

lab1 = image[top_left_y:top_left_y + side_length, top_left_x:top_left_x + side_length]

cv2.imwrite('lab1.jpg', lab1)

heightCopy, widthCopy, _ = lab1.shape

with open('properties.txt', 'w') as file:
        file.write(f"Cropped Image Resolution: {heightCopy}x{widthCopy}\n")

print(f"Properties of Original Image: {height}x{width}")

whitepixelCount = (grayscaleImage == 255).sum()

print(f"Number of white pixels: {whitepixelCount}")

grayscaleImage[grayscaleImage == 255] = 0

cv2.imwrite('lab1_modified.jpg', grayscaleImage)

cv2.imshow("OpenCV Image", image)
cv2.imshow("GrayScale Image", grayscaleImage)
cv2.waitKey(0)
