import numpy as np
import cv2

if __name__ == '__main__':
    img = cv2.imread('./images/coins1.jpg', cv2.CV_8UC1)
    out = img

    gaussian_img = cv2.GaussianBlur(img, (41, 41), 0)
    thresehold_img = cv2.adaptiveThreshold(gaussian_img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 15, 2)

    kernel = np.ones((9,9), np.uint8)
    closing = cv2.morphologyEx(thresehold_img, cv2.MORPH_CLOSE, kernel, iterations=1)

    contours_img = closing.copy()
    image, contours, hierarchy = cv2.findContours(contours_img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        area = cv2.contourArea(contour)

        if area < 1000:
            continue

        if len(contour) < 5:
            continue

        ellipse = cv2.fitEllipse(contour)
        cv2.ellipse(out, ellipse, color=(0,0,0), thickness=5)

    cv2.imwrite('closing.jpg', closing)
    cv2.imwrite('out.jpg', out)
    cv2.waitKey(0)
