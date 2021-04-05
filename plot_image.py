import cv2
from PIL import Image
from matplotlib import pyplot as plt


image = cv2.cvtColor(
    cv2.imread('./dump/image.ppm'),
    cv2.COLOR_BGR2RGB
)
image = Image.fromarray(image)
image.save('./dump/image.png')
print('Image saved as ./dump/image.png')

plt.figure(figsize=(10, 10))
plt.imshow(image)
plt.axis('off')
plt.show()
