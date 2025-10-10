// ==================================================================================================
// OOP Assignment 1
//
//  Team members:
//   1. Ramez Rizk Hassan - ID: 20240185 (Did Filters: 1, 4, 7, 10, 16)
//   2. Nour Khalaf Ahmed - ID: 20240636 (Did Filters: 2, 5, 8, 11, 13)
//   3. Ahmed Yasser Nada - ID: 20240824 (Did Filters: 3, 6, 9, 12, 15)
//
//  Section 18
// ==================================================================================================

#include "Image_Class.h"
#include <bits/stdc++.h>
using namespace std;

void applyGrayscale(Image& image);          // Filter 1
void applyBlackAndWhite(Image& image);      // Filter 2
void applyInvert(Image& image);             // Filter 3
void applyMerge(Image& image);              // Filter 4
void applyFlip(Image& image);               // Filter 5
void applyRotate(Image& image);             // Filter 6
void applyDarkenAndLighten(Image& image);   // Filter 7
void applyCrop(Image& image);               // Filter 8
void applyFrame(Image& image);              // Filter 9
void applyEdgeDetection(Image& image);      // Filter 10
void applyResize(Image& image);             // Filter 11
void applyBlur(Image& image);               // Filter 12
// bonuses
void applySunlight(Image& image);           // Filter 13
void applyTVSnow(Image& image);             // Filter 15
void applyPurple(Image& image);             // Filter 16

void loadImage(Image& image);
void saveImage(Image& image);

int main() {
    // the random generator runs at the start of the program :)
    srand(time(0));
    
    Image currentImage;
    bool imageIsModified = false;

    cout << "Ahlan ya user ya habibi :)" << endl;

    loadImage(currentImage);

    while (true) {
        cout << "\nPlease select a filter to apply or an option:" << endl;
        cout << "1- Grayscale Conversion" << endl;
        cout << "2- Black and White" << endl;
        cout << "3- Invert Image" << endl;
        cout << "4- Merge Images" << endl;
        cout << "5- Flip Image" << endl;
        cout << "6- Rotate Image" << endl;
        cout << "7- Darken and Lighten Image" << endl;
        cout << "8- Crop Image" << endl;
        cout << "9- Add a Frame" << endl;
        cout << "10- Detect Image Edges" << endl;
        cout << "11- Resize Image" << endl;
        cout << "12- Blur Image" << endl;
        cout << "13- Enhance Sunlight (Wano Filter)" << endl;
        cout << "15- Old TV Effect" << endl;
        cout << "16- Purple Filter" << endl;
        cout << "s- Save the image to a file" << endl;
        cout << "l- Load a new image" << endl;
        cout << "0- Exit" << endl;
        cout << "Your choice: ";

        string choice;
        cin >> choice;

        if (choice == "1") {
            applyGrayscale(currentImage);
            imageIsModified = true;
        } else if (choice == "2") {
            applyBlackAndWhite(currentImage);
            imageIsModified = true;
        } else if (choice == "3") {
            applyInvert(currentImage);
            imageIsModified = true;
        } else if (choice == "4") {
            applyMerge(currentImage);
            imageIsModified = true;
        } else if (choice == "5") {
            applyFlip(currentImage);
            imageIsModified = true;
        } else if (choice == "6") {
            applyRotate(currentImage);
            imageIsModified = true;
        } else if (choice == "7") {
            applyDarkenAndLighten(currentImage);
            imageIsModified = true;
        } else if (choice == "8") {
            applyCrop(currentImage);
            imageIsModified = true;
        } else if (choice == "9") {
            applyFrame(currentImage);
            imageIsModified = true;
        } else if (choice == "10") {
            applyEdgeDetection(currentImage);
            imageIsModified = true;
        } else if (choice == "11") {
            applyResize(currentImage);
            imageIsModified = true;
        } else if (choice == "12") {
            applyBlur(currentImage);
            imageIsModified = true;
        } else if (choice == "13") {
            applySunlight(currentImage);
            imageIsModified = true;
        } else if (choice == "15") {
            applyTVSnow(currentImage);
            imageIsModified = true;
        } else if (choice == "16") {
            applyPurple(currentImage);
            imageIsModified = true;
        } else if (choice == "s" || choice == "S") {
            saveImage(currentImage);
            imageIsModified = false;
        } else if (choice == "l" || choice == "L") {
            if (imageIsModified) {
                char saveChoice;
                cout << "You have unsaved changes. Do you want to save them? (y/n): ";
                cin >> saveChoice;
                if (saveChoice == 'y' || saveChoice == 'Y') {
                    saveImage(currentImage);
                }
            }
            loadImage(currentImage);
            imageIsModified = false;
        } else if (choice == "0") {
            if (imageIsModified) {
                char saveChoice;
                cout << "You have unsaved changes. Do you want to save them before exiting? (y/n): ";
                cin >> saveChoice;
                if (saveChoice == 'y' || saveChoice == 'Y') {
                    saveImage(currentImage);
                }
            }
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void loadImage(Image& image) {
    string filename;
    while (true) {
        cout << "Please enter the filename of the image to process: ";
        cin >> filename;
        try {
            image.loadNewImage(filename);
            cout << "Image loaded successfully!" << endl;
            break;
        } catch (const invalid_argument& error_from_loading_file) {
            cout << "Error: " << error_from_loading_file.what() << ". Please enter a valid filename." << endl;
        }
    }
}

void saveImage(Image& image) {
    string filename;
    bool isSaved = false;

    do {
        cout << "Enter the filename to save the image as (e.g., output.jpg): ";
        cin >> filename;
        try {
            image.saveImage(filename);
            cout << "Image saved successfully as " << filename << endl;
            isSaved = true;
        } catch (const invalid_argument& error) {
            cout << "Error: Invalid filename or extension. Please use .jpg, .bmp, .png, or .jpeg" << endl;
        }
    } while (!isSaved);
}

// Filter 1
void applyGrayscale(Image& image) {
    cout << "Applying Grayscale Filter..." << endl;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = avg;
            }
        }
    }
    cout << "Grayscale Filter applied successfully." << endl;
}

// Filter 2
void applyBlackAndWhite(Image& image) {
    cout << "Applying Black and White Filter..." << endl;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            unsigned char newValue = (avg < 128) ? 0 : 255;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = newValue;
            }
        }
    }
    cout << "Black and White Filter applied successfully." << endl;
}

// Filter 3
void applyInvert(Image& image) {
    cout << "Applying Invert Filter..." << endl;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    cout << "Invert Filter applied successfully." << endl;
}


// helping func. of the merge
Image resizeForMerge(const Image& original, int newWidth, int newHeight) { 
    Image resized(newWidth, newHeight);
    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            int orig_i = i * original.width / newWidth;
            int orig_j = j * original.height / newHeight;
            for (int k = 0; k < 3; ++k) {
                resized(i, j, k) = original(orig_i, orig_j, k);
            }
        }
    }
    return resized;
}

// Filter 4
void applyMerge(Image& image) {
    cout << "Applying Merge Filter..." << endl;
    Image image2;
    cout << "Loading the second image for merging..." << endl;
    loadImage(image2);
    Image resultImage;

    if (image.width == image2.width && image.height == image2.height) {
        resultImage = Image(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    resultImage(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;
                }
            }
        }
    } else {
        int choice;
        cout << "Images have different sizes. Please choose an option:" << endl;
        cout << "1. Resize both to the largest dimensions and then merge." << endl;
        cout << "2. Merge the common smaller area." << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        if (choice == 1) {
            int maxWidth = max(image.width, image2.width);
            int maxHeight = max(image.height, image2.height);
            Image resized1 = resizeForMerge(image, maxWidth, maxHeight);
            Image resized2 = resizeForMerge(image2, maxWidth, maxHeight);
            resultImage = Image(maxWidth, maxHeight);
            for (int i = 0; i < maxWidth; ++i) {
                for (int j = 0; j < maxHeight; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        resultImage(i, j, k) = (resized1(i, j, k) + resized2(i, j, k)) / 2;
                    }
                }
            }
        } else if (choice == 2) {
            int commonWidth = min(image.width, image2.width);
            int commonHeight = min(image.height, image2.height);
            resultImage = Image(commonWidth, commonHeight);
            for (int i = 0; i < commonWidth; ++i) {
                for (int j = 0; j < commonHeight; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        resultImage(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;
                    }
                }
            }
        } else {
            cout << "Invalid choice! Returning to main menu." << endl;
            return;
        }
    }
    image = resultImage;
    cout << "Merge Filter applied successfully." << endl;
}

// Filter 5
void applyFlip(Image& image) {
    cout << "Applying Flip Filter..." << endl;
    Image flippedImage(image.width, image.height);
    char type;
    cout << "Enter (H) for Horizontal Flip or (V) for Vertical Flip: ";
    cin >> type;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (type == 'V' || type == 'v') {
                for (int k = 0; k < 3; ++k) {
                    flippedImage(i, image.height - 1 - j, k) = image(i, j, k);
                }
            } else if (type == 'H' || type == 'h') {
                for (int k = 0; k < 3; ++k) {
                    flippedImage(image.width - 1 - i, j, k) = image(i, j, k);
                }
            }
        }
    }
    image = flippedImage;
    cout << "Flip Filter applied successfully." << endl;
}

// Filter 6
void applyRotate(Image& image) {
    cout << "Applying Rotate Filter..." << endl;
    string choice;
    cout << "Rotate (90), (180), or (270) degrees clockwise? ";
    cin >> choice;

    int oldWidth = image.width;
    int oldHeight = image.height;

    if (choice == "90") {
        Image rotatedImage(oldHeight, oldWidth);
        for (int i = 0; i < oldWidth; ++i) {
            for (int j = 0; j < oldHeight; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    rotatedImage((oldHeight - 1) - j, i, k) = image(i, j, k);
                }
            }
        }
        image = rotatedImage;
        cout << "Image rotated 90 degrees clockwise successfully." << endl;
    } else if (choice == "180") {
        Image rotatedImage(oldWidth, oldHeight);
        for (int i = 0; i < oldWidth; ++i) {
            for (int j = 0; j < oldHeight; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    rotatedImage((oldWidth - 1) - i, (oldHeight - 1) - j, k) = image(i, j, k);
                }
            }
        }
        image = rotatedImage;
        cout << "Image rotated 180 degrees clockwise successfully." << endl;
    } else if (choice == "270") {
        Image rotatedImage(oldHeight, oldWidth);
        for (int i = 0; i < oldWidth; ++i) {
            for (int j = 0; j < oldHeight; ++j) {
                for (int k = 0; k < image.channels; ++k) {
                    rotatedImage(j, (oldWidth - 1) - i, k) = image(i, j, k);
                }
            }
        }
        image = rotatedImage;
        cout << "Image rotated 270 degrees clockwise successfully." << endl;
    } else {
        cout << "Invalid rotation angle. Please choose 90, 180, or 270." << endl;
    }
}

// Filter 7
void applyDarkenAndLighten(Image& image) {
    cout << "Applying Darken/Lighten Filter..." << endl;
    int choice;
    cout << "Select your choice:" << endl;
    cout << "1. Darken the image by 50%" << endl;
    cout << "2. Lighten the image by 50%" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) *= 0.5;
                }
            }
        }
        cout << "Image darkened successfully." << endl;
    } else if (choice == 2) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int newValue = image(i, j, k) * 1.5;
                    if (newValue > 255) {
                        image(i, j, k) = 255;
                    } else {
                        image(i, j, k) = newValue;
                    }
                }
            }
        }
        cout << "Image lightened successfully." << endl;
    } else {
        cout << "Invalid choice. No filter applied." << endl;
    }
}

// Filter 8
void applyCrop(Image& image) {
    cout << "Applying Crop Filter..." << endl;
    int x, y, w, h;
    
    cout << "Current image dimensions: " << image.width << "x" << image.height << endl;
    cout << "Enter The (X, Y) as the starting point (upper left corner):" << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    
    // the start point (x,y)
    if (x < 0 || y < 0 || x >= image.width || y >= image.height) {
        cout << "Error: Starting point is outside the image boundaries!" << endl;
        return;
    }
    
    cout << "Enter The (W, H) as The Dimensions of The Area to Cut:" << endl;
    cout << "Width: ";
    cin >> w;
    cout << "Height: ";
    cin >> h;
    
    // chek if the diemntions are correct
    if (w <= 0 || h <= 0) {
        cout << "Error: Width and Height must be positive numbers!" << endl;
        return;
    }
    
    if (x + w > image.width || y + h > image.height) {
        cout << "Error: The crop area exceeds image boundaries!" << endl;
        cout << "Maximum width from X=" << x << " is " << (image.width - x) << endl;
        cout << "Maximum height from Y=" << y << " is " << (image.height - y) << endl;
        return;
    }
    
    Image croppedImage(w, h);
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                croppedImage(i, j, k) = image(x + i, y + j, k);
            }
        }
    }
    
    image = croppedImage;
    cout << "Crop Filter applied successfully. New dimensions: " << w << "x" << h << endl;
}

// Filter 9
void applyFrame(Image& image) {
    cout << "Applying Frame Filter..." << endl;
    unsigned char frameR, frameG, frameB;
    char colorChoice;
    cout << "Choose frame color (r)ed, (g)reen, or (b)lue: ";
    cin >> colorChoice;
    switch (tolower(colorChoice)) {
        case 'r': frameR = 255; frameG = 0; frameB = 0; break;
        case 'g': frameR = 0; frameG = 255; frameB = 0; break;
        case 'b': frameR = 0; frameG = 0; frameB = 255; break;
        default:
            cout << "Invalid color. Defaulting to black." << endl;
            frameR = 0; frameG = 0; frameB = 0;
            break;
    }
    int frameSize;
    cout << "Enter frame thickness (e.g., 10): ";
    cin >> frameSize;
    if (frameSize <= 0 || frameSize * 2 >= image.width || frameSize * 2 >= image.height) {
        cout << "Invalid frame size. It's either too small or too large for the image." << endl;
        return;
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < frameSize || i >= (image.width - frameSize) || j < frameSize || j >= (image.height - frameSize)) {
                image(i, j, 0) = frameR;
                image(i, j, 1) = frameG;
                image(i, j, 2) = frameB;
            }
        }
    }
    cout << "Frame applied successfully." << endl;
}

// Filter 10
void applyEdgeDetection(Image& image) {
    cout << "Applying Edge Detection Filter..." << endl;

    // temp black and white version
    Image bwImage = image;
    for (int i = 0; i < bwImage.width; ++i) {
        for (int j = 0; j < bwImage.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += bwImage(i, j, k);
            }
            avg /= 3;
            unsigned char newValue;
            if(avg < 128)
            {
                newValue = 0;
            }

            else
            {
                newValue = 255;
            }

            for (int k = 0; k < 3; ++k) {
                bwImage(i, j, k) = newValue;
            }
        }
    }

    Image edgeImage(image.width, image.height);
    // checking neighbours with arrs
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            bool is_edge = false;
            int current_pixel = bwImage(i, j, 0);

            // real checking ^_^
            for (int dir = 0; dir < 8; ++dir) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (current_pixel != bwImage(nx, ny, 0)) {
                    is_edge = true;
                    break;
                }
            }

            unsigned char color;
            if(is_edge)
            {
                color = 0;
            }

            else
            {
                color = 255;
            }

            for (int k = 0; k < 3; ++k) {
                edgeImage(i, j, k) = color;
            }
        }
    }
    image = edgeImage;
    cout << "Edge Detection Filter applied successfully." << endl;
}

// Filter 11
void applyResize(Image& image) {
    cout << "Applying Resize Filter..." << endl;
    int newWidth, newHeight;
    
    cout << "Current image dimensions: " << image.width << "x" << image.height << endl;
    cout << "Enter new width: ";
    cin >> newWidth;
    cout << "Enter new height: ";
    cin >> newHeight;
    
    if (newWidth <= 0 || newHeight <= 0) {
        cout << "Error: Width and Height must be positive numbers!" << endl;
        return;
    }
    
    if (newWidth > 10000 || newHeight > 10000) {
        cout << "Warning: Very large dimensions may cause memory issues." << endl;
        char confirm;
        cout << "Continue? (y/n): ";
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            return;
        }
    }
    
    Image resized(newWidth, newHeight);
    float x_ratio = (float)image.width / newWidth;
    float y_ratio = (float)image.height / newHeight;
    
    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            int srcX = (int)(i * x_ratio);
            int srcY = (int)(j * y_ratio);
            
            if (srcX >= image.width) srcX = image.width - 1;
            if (srcY >= image.height) srcY = image.height - 1;
            
            for (int c = 0; c < 3; ++c) {
                resized(i, j, c) = image(srcX, srcY, c);
            }
        }
    }
    
    image = resized;
    cout << "Resize Filter applied successfully. New dimensions: " << newWidth << "x" << newHeight << endl;
}

// Filter 12
void applyBlur(Image& image) {
    cout << "Applying Blur Filter..." << endl;
    int radius;
    cout << "Enter blur radius (1 for a light blur, 15 for a strong blur): ";
    cin >> radius;
    if (radius < 1) {
        cout << "Invalid radius. Please enter a number greater than 0." << endl;
        return;
    }
    Image blurredImage(image.width, image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            long sumR = 0, sumG = 0, sumB = 0;
            int pixelCount = 0;
            for (int x = -radius; x <= radius; ++x) {
                for (int y = -radius; y <= radius; ++y) {
                    int neighborI = i + x;
                    int neighborJ = j + y;
                    if (neighborI >= 0 && neighborI < image.width && neighborJ >= 0 && neighborJ < image.height) {
                        sumR += image(neighborI, neighborJ, 0);
                        sumG += image(neighborI, neighborJ, 1);
                        sumB += image(neighborI, neighborJ, 2);
                        pixelCount++;
                    }
                }
            }
            blurredImage(i, j, 0) = sumR / pixelCount;
            blurredImage(i, j, 1) = sumG / pixelCount;
            blurredImage(i, j, 2) = sumB / pixelCount;
        }
    }
    image = blurredImage;
    cout << "Blur filter applied successfully." << endl;
}

// Filter 13
void applySunlight(Image& image) {
    cout << "Applying Sunlight Enhancement Filter..." << endl;
    cout << "This filter enhances natural sunlight in the image (Wano Filter 13)" << endl;
    
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int r = image(i, j, 0);
            int g = image(i, j, 1);
            int b = image(i, j, 2);
            
            r = r * 1.3;
            g = g * 1.3;
            b = b * 1.2;  
            
            r += 20;  
            g += 15;  
            
            if (r > 255) r = 255;
            if (r < 0) r = 0;
            if (g > 255) g = 255;
            if (g < 0) g = 0;
            if (b > 255) b = 255;
            if (b < 0) b = 0;
            
            image(i, j, 0) = r;
            image(i, j, 1) = g;
            image(i, j, 2) = b;
        }
    }
    
    cout << "Sunlight Enhancement Filter applied successfully." << endl;
    cout << "The image now has better natural sunlight!" << endl;
}

// Filter 15
void applyTVSnow(Image& image) {
    cout << "Applying Old TV Filter..." << endl;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int originalValue = image(i, j, k);
                int disturbance = (rand() % 101) - 50;
                int newValue = originalValue + disturbance;
                if (newValue > 255) newValue = 255;
                if (newValue < 0) newValue = 0;
                image(i, j, k) = (unsigned char)newValue;
            }
        }
    }
    cout << "Old TV Filter applied successfully." << endl;
}

// Filter 16
void applyPurple(Image& image) {
    cout << "Applying Purple Filter..." << endl;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int r = image(i, j, 0);
            int g = image(i, j, 1);
            int b = image(i, j, 2);

            int newr = r * 1.2;
            int newg = g * 0.8;
            int newb = b * 1.3;

            if (newr > 255) newr = 255;
            if (newg > 255) newg = 255;
            if (newb > 255) newb = 255;

            image(i, j, 0) = newr;
            image(i, j, 1) = newg;
            image(i, j, 2) = newb;
        }
    }
    cout << "Purple Filter applied successfully." << endl;
}