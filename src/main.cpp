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