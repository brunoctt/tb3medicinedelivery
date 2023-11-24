import cv2


def calculate_centroid(resolution, image):
        """
        Calculates centroid of given image and returns it's x and y values

        Args:
            resolution (tuple[int, int, int]):
            image (np.ndarray): input image

        Returns:
            tuple[int, int]: x and y momentums
        """
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        blur = cv2.GaussianBlur(gray, (5, 5), 0)
        _, binary = cv2.threshold(blur, 127, 255, cv2.THRESH_BINARY)
        
        # Removing parts without floor
        y_shape = 0
        while binary[y_shape, :].all():
            y_shape += 1
        
        if y_shape == resolution[0]:
            return 0, 0, binary
        
        half_bottom_floor = (resolution[0] - y_shape) // 2
        binary = binary[-half_bottom_floor:, :]

        # centroid navigation, calculate moments of binary image
        moments = cv2.moments(255 - binary)

        try:
            # calculate x,y coordinate of center
            momentum_x = int(moments["m10"] / max(moments["m00"], 1))
            momentum_y = int(moments["m01"] / max(moments["m00"], 1))
        except ValueError:
            # in case of error, return value to center of image
            momentum_x = resolution[1] / 2
            momentum_y = resolution[0] / 2

        return momentum_x, momentum_y, binary


def search_for_intersection(binary):
    # Searching for intersections
    contours, _ = cv2.findContours(binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    return len(contours) > 2 or len(contours) == 0


def track_line(resolution, image): 
    momentum_x, _, binary = calculate_centroid(resolution, image)
    mean_x = max(resolution) / 2
    relative_position = (momentum_x - mean_x) / mean_x
    
    found_intersection = search_for_intersection(binary)
    
    return relative_position, found_intersection


