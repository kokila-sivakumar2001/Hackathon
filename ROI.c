import cv2

# Load the video file
cap = cv2.VideoCapture("video.mp4")

# Load the pedestrian detector
detector = cv2.HOGDescriptor()
detector.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

while True:
# Read a frame from the video
ret, frame = cap.read()
if not ret:
break

# Detect pedestrians in the frame boxes, weights = detector.detectMultiScale(frame, winStride=(8, 8))

# Draw bounding boxes around the pedestrians
for (x, y, w, h) in boxes:
cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)

# Show the frame
cv2.imshow("Frame", frame)
if cv2.waitKey(1) & 0xFF == ord('q'):
break

cap.release()
cv2.destroyAllWindows()
