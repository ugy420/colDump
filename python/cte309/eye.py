import cv2
import os
import sys

if len(sys.argv) < 2:
    print("Usage: python batch_face_detection.py <directory_path>")
    sys.exit(1)

directoryPath = sys.argv[1]

# Check if the provided path is a directory
if not os.path.isdir(directoryPath):
    print(f"The provided path is not a directory: {directoryPath}")
    sys.exit(1)

# Load the pre-trained face detection model
faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

# Process each image in the directory
for filename in os.listdir(directoryPath):
    # Only process files with image extensions
    if filename.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.tiff')):
        imagePath = os.path.join(directoryPath, filename)

        # Load the image
        image = cv2.imread(imagePath)
        if image is None:
            print(f"Could not open or find the image: {imagePath}")
            continue

        # Convert the image to grayscale
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        # Detect faces in the image
        faces = faceCascade.detectMultiScale(
            gray,
            scaleFactor=1.3,
            minNeighbors=3,
            minSize=(30, 30)
        )

        print(f"[INFO] Found {len(faces)} Faces in {filename}.")

        # Draw rectangles around detected faces and save each face as a separate image
        for (x, y, w, h) in faces:
            cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
            roi_color = image[y:y + h, x:x + w]
            face_filename = os.path.join(directoryPath, f"{os.path.splitext(filename)[0]}_{w}x{h}_faces.jpg")
            cv2.imwrite(face_filename, roi_color)
            print(f"[INFO] Object found. Saving locally as {face_filename}")

        # Save the image with rectangles drawn around faces
        detected_image_filename = os.path.join(directoryPath, f"{os.path.splitext(filename)[0]}_faces_detected.jpg")
        status = cv2.imwrite(detected_image_filename, image)
        print(f"[INFO] Image {detected_image_filename} written to filesystem: {status}")
