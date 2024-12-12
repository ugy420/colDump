import cv2
Lenna = cv2.imread("Lenna.jpg")
GsLenna = cv2.cvtColor(Lenna,cv2.COLOR_BGR2GRAY)

min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(GsLenna)

height, width = GsLenna.shape[:2]
max_pxl_val = 0
min_pxl_val = 255
for i in range (height):
    for j in range (width):
        pxl_val = GsLenna[i,j]
        if(pxl_val>max_pxl_val):
            max_pxl_val = pxl_val
        if(pxl_val<min_pxl_val):
            min_pxl_val = pxl_val

count_min = 0
for i in range (height):
    for j in range (width):
        if(GsLenna[i,j] == min_pxl_val):
            count_min+=1

print(f"Highest valued pixel (using in-build function) {max_val}")
print(f"Highest valued pixel (without in-build function) {max_pxl_val}")
print(f"Lowest valued pixel (without in-build function) {min_pxl_val}")
print(f"Lowest valued pixel occurences {count_min}")
cv2.imwrite('GsLenna.jpg', GsLenna)