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